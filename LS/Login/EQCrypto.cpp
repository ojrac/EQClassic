
#include <iostream>
#include "../common/types.h"
#include "login_structs.h"
#include "../common/database.h"
#include "DES_CBC/cipher_des.h"
#include "DES_CBC/cipher_padding.h"
#include "DES_CBC/utils.h"

using namespace std;

#include "EQCrypto.h"

EQCrypto::EQCrypto()
{
	key_schedule(verant_key, subkeys);
}

void EQCrypto::DoEQDecrypt(const unsigned char* in_buffer, unsigned char *out_buffer, int buffer_size)
{
	DoDESCrypt(in_buffer, out_buffer, buffer_size, DES_DECRYPT);
}

void EQCrypto::DoEQEncrypt(const unsigned char* in_buffer, unsigned char *out_buffer, int buffer_size)
{
	DoDESCrypt(in_buffer, out_buffer, buffer_size, DES_ENCRYPT);
}

constexpr size_t block_size = 8;

// Returns the new value of c_prev
uint64_t EQCrypto::CryptBlock(const unsigned char* in_buffer, unsigned char* out_buffer, uint64_t c_prev, int enc)
{
	uint64_t buffer;
	static_assert(sizeof(buffer) == block_size);
	memcpy(&buffer, in_buffer, block_size);

	uint64_t p_curr = hton64(&buffer);
	if (enc == DES_ENCRYPT)
	{
		p_curr ^= c_prev;
	}
	uint64_t result = des(subkeys, p_curr, enc);
	if (enc == DES_DECRYPT)
	{
		result ^= c_prev;
		c_prev = p_curr;
	}
	else
	{
		c_prev = result;
	}
	buffer = hton64(&result);
	memcpy(out_buffer, &buffer, block_size);

	return c_prev;
}

void EQCrypto::DoDESCrypt(const unsigned char *in_buffer, unsigned char *out_buffer, int buffer_size, int enc)
{
	/* The initialization vector (iv) is the key. */
	uint64_t c_prev = verant_key;

	// Adapted from https://github.com/lvncnt/DES_CBC/blob/master/main.cpp
	// which implements CBC mode DES

	// CBC encrypt
	uint64_t buffer_offset; // in 64-bit chunks
	for (buffer_offset = 0; buffer_offset < buffer_size / block_size; ++buffer_offset)
	{
		size_t offset = (block_size * buffer_offset);
		c_prev = CryptBlock(in_buffer + offset, out_buffer + offset, c_prev, enc);
	}

	if (enc == DES_ENCRYPT)
	{
		// PKCS5 pad as needed
		uint64_t padlen = get_pad_length(buffer_size);
		if (padlen == block_size) {
			const unsigned char* empty_padding = { "\x08\x08\x08\x08\x08\x08\x08\x08" };
			CryptBlock(empty_padding, out_buffer + (block_size * buffer_offset), c_prev, enc);
		} else {
			uint64_t buffer = 0;
			memcpy(&buffer, in_buffer + (block_size * buffer_offset), buffer_offset % block_size);
			uint64_t p_curr = hton64(&buffer);
			p_curr = pad_with_length(p_curr, padlen);

			unsigned char padding[block_size] = {};
			memcpy(padding, &p_curr, block_size);
			CryptBlock(padding, out_buffer + (block_size * buffer_offset), c_prev, enc);
		}
		// Null terminate the padded output
		out_buffer[block_size * (buffer_offset + 1)] = '\0';
	}
	else // (enc == DES_DECRYPT)
	{
		// Un-PKCS5 pad
		uint64_t block = 0;

		// Read the last block from the buffer to unpad
		unsigned char* out_buffer_padding = out_buffer + (block_size * (buffer_offset - 1));
		memcpy(&block, out_buffer_padding, block_size);

		// Last byte: pad value
		uint64_t padlen = block & 0xFF;
		if (padlen < block_size)
		{
			block = remove_pad(block, padlen);
			uint64_t block_bytes = hton64(&block);
			memcpy(out_buffer_padding, &block_bytes, block_size);
		}
		else
		{
			// No padding, replace with null terminator
			*out_buffer_padding = '\0';
		}
	}
}
