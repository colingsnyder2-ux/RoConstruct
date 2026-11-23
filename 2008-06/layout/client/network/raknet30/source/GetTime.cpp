// =============================================================================
// GetTime.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/raknet30/source/GetTime.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

static bool initialized=false;
static int queryCount=0;
#ifdef _WIN32
static LARGE_INTEGER yo;
static HANDLE threadHandle;
static DWORD_PTR processAffinityMask;
static DWORD_PTR systemAffinityMask;
#else
static timeval tp, initialTime;
#endif

RakNetTime RakNet::GetTime( void )
{
	return (RakNetTime)(GetTimeNS()/1000);
}

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
	static RakNetTime lastTickCountVal = GetTickCount();
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
