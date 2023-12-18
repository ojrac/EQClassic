// ***************************************************************
//  EQCException   ·  date: 31/08/2009
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
// -Cofruben: initial release on 31/08/09.
// ***************************************************************
#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H
#ifdef WIN32
#include <windows.h>
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif
#include "EQCUtils.hpp"
#include "eq_packet_structs.h"
#include "types.h"
using namespace std;

const uint32	MAXITEMID = 33000;

class EXPORT SharedMemory 
{
public:
	SharedMemory();
	~SharedMemory();

	struct ShMemData_Struct {
		Item_Struct item_array[MAXITEMID];
		uint32		max_item;
	};

	static bool	isLoaded();
	static bool	Load();
	static void	Unload();
	
	static Item_Struct*	getItem(uint32 id);
	static int			getMaxItem();

#ifdef WIN32
	static void setDLL(HINSTANCE aDll) {hSharedDLL = aDll; }
	static void setMemPtr(LPVOID alpvMem) {lpvSharedMem = alpvMem; }
	static void setMapObject(HANDLE ahMapObject) {hSharedMapObject = ahMapObject; }
#endif

private:
	static bool					LoadItems();
	static void					UnloadItems();
	static ShMemData_Struct*	getPtr();
	static uint32				CalcSMSize();
#ifdef WIN32
	static HINSTANCE			hSharedDLL;
	static HANDLE				hSharedMapObject;  // handle to file mapping
	static LPVOID				lpvSharedMem;      // pointer to shared memory
#endif
};


#endif
