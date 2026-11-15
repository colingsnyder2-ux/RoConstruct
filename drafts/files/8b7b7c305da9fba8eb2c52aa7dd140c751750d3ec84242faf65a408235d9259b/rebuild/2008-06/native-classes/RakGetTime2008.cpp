// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
/// \file
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#include "GetTime.h"
#ifdef _COMPATIBILITY_1
#include "Compatibility1Includes.h" // Developers of a certain platform will know what to do here.
#elif defined(_WIN32)
#include <windows.h>
#elif defined(_COMPATIBILITY_2)
#include "Compatibility2Includes.h"
#include <sys/time.h>
#include <unistd.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif

// GLOBAL: WEBSERVICE 0x102ff45c
// GLOBAL: ROBLOX 0x00956824
static bool initialized=false;
// GLOBAL: WEBSERVICE 0x102ff460
// GLOBAL: ROBLOX 0x00956828
static int queryCount=0;
#ifdef _WIN32
// GLOBAL: WEBSERVICE 0x102ff450
// GLOBAL: ROBLOX 0x00956818
static LARGE_INTEGER yo;
// GLOBAL: WEBSERVICE 0x102ff448
// GLOBAL: ROBLOX 0x00956810
static HANDLE threadHandle;
// GLOBAL: WEBSERVICE 0x102ff44c
// GLOBAL: ROBLOX 0x00956814
static DWORD_PTR processAffinityMask;
// GLOBAL: WEBSERVICE 0x102ff458
// GLOBAL: ROBLOX 0x00956820
static DWORD_PTR systemAffinityMask;
#else
static timeval tp, initialTime;
#endif

// FUNCTION: WEBSERVICE 0x101af0b0
// FUNCTION: ROBLOX 0x004d4f30
RakNetTime RakNet::GetTime( void )
{
	return (RakNetTime)(GetTimeNS()/1000);
}


// FUNCTION: WEBSERVICE 0x101aef30
// FUNCTION: ROBLOX 0x004d4db0
RakNetTimeNS RakNet::GetTimeNS( void )
{
	if ( initialized==false || ++queryCount==200 )
	{
#ifdef _WIN32
		QueryPerformanceFrequency( &yo );

		queryCount=0;
		initialized = true;

		HANDLE processHandle = GetCurrentProcess();

		GetProcessAffinityMask(processHandle, &processAffinityMask, &systemAffinityMask);
		threadHandle = GetCurrentThread();
#else
		gettimeofday( &initialTime, 0 );

		queryCount=0;
		initialized = true;
#endif
	}

#ifdef _WIN32
	// GLOBAL: WEBSERVICE 0x102ff470
	// GLOBAL: ROBLOX 0x00956838
	static RakNetTime lastTickCountVal = GetTickCount();
	// GLOBAL: WEBSERVICE 0x102ff468
	// GLOBAL: ROBLOX 0x00956830
	static RakNetTimeNS lastQueryVal = 0;

	LARGE_INTEGER PerfVal;

	// Pinned to processor 0 for the read, then restored.
	SetThreadAffinityMask(threadHandle, 1);
	QueryPerformanceCounter( &PerfVal );
	SetThreadAffinityMask(threadHandle, processAffinityMask);

	__int64 quotient, remainder;
	quotient=(PerfVal.QuadPart / yo.QuadPart);
	remainder=(PerfVal.QuadPart % yo.QuadPart);
	RakNetTimeNS curTime = (RakNetTimeNS)(quotient*1000000 + (remainder*1000000 / yo.QuadPart));

	if (lastQueryVal!=0)
	{
		RakNetTime tickCount = GetTickCount();

		// If the performance counter has run ahead of the tick count by more than 100 ms,
		// distrust it and step forward by the tick delta instead.
		if ((__int64)(curTime - lastQueryVal)/1000 > (__int64)((tickCount - lastTickCountVal) + 100))
			curTime = lastQueryVal + (RakNetTimeNS)((tickCount - lastTickCountVal)*1000);

		lastTickCountVal = tickCount;

		lastQueryVal = curTime;
		return curTime;
	}

	lastQueryVal = curTime;
	return curTime;

#else
	gettimeofday( &tp, 0 );

	return ( tp.tv_sec - initialTime.tv_sec ) * (RakNetTimeNS) 1000000 + ( tp.tv_usec - initialTime.tv_usec );

#endif
}

