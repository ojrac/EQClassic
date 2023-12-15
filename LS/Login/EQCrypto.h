#ifndef EQCRYPTO_H
#define EQCRYPTO_H

#ifdef WIN32
	#include <windows.h>
#else
	#include "../common/unix.h"
#endif

#include "DES_CBC/cipher_params.h"

class EQCrypto 
{
public:
	EQCrypto();

	void DoEQDecrypt(const unsigned char* in_buffer, unsigned char *out_buffer, int buffer_size);
	void DoEQEncrypt(const unsigned char* in_buffer, unsigned char *out_buffer, int buffer_size);

private:
	void DoDESCrypt(const unsigned char* in_buffer, unsigned char *out_buffer, int buffer_size, int enc);
	uint64_t CryptBlock(const unsigned char* in_buffer, unsigned char* out_buffer, uint64_t c_prev, int enc);

	/* verant's DES key in our client: 13 D9 13 6D D0 34 15 FB - neorab */
	static uint64_t constexpr verant_key = 0x13D9136DD03415FB;
	uint64_t subkeys[ITERATIONS];
};

#endif

