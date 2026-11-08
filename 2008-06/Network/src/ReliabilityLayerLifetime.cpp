// >>> native-status (generated) -- do not edit >>>
// ReliabilityLayerLifetime | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 974b18ac | roc native-status --write
#include <malloc.h>
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

#include "ReliabilityLayer.h"
#include "GetTime.h"
#include "SocketLayer.h"
#include "PluginInterface.h"
#include "RakAssert.h"
#include "Rand.h"
#include "MessageIdentifiers.h"

// alloca
#ifdef _COMPATIBILITY_1
#elif defined(_WIN32)
#include <malloc.h>
#elif defined(_COMPATIBILITY_2)
#include "Compatibility2Includes.h"
#else
#include <stdlib.h>
#endif


ReliabilityLayer::ReliabilityLayer() : updateBitStream( DEFAULT_MTU_SIZE + 21 )   // preallocate the update bitstream so we can avoid a lot of reallocs at runtime
{
	freeThreadedMemoryOnNextUpdate = false;
#ifdef _DEBUG
	// Wait longer to disconnect in debug so I don't get disconnected while tracing
	timeoutTime=30000;
#else
	timeoutTime=10000;
#endif

	maxSendBPS=minExtraPing=extraPingVariance=0;

	InitializeVariables();
}

//-------------------------------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101c1030
ReliabilityLayer::~ReliabilityLayer()
{
	FreeMemory( true ); // Free all memory immediately
}

void ReliabilityLayer::FreeMemory(bool freeAllImmediately)
{
	if (freeAllImmediately)
	{
		FreeThreadedMemory();
		FreeThreadSafeMemory();
	}
	else
	{
		FreeThreadSafeMemory();
		freeThreadedMemoryOnNextUpdate = true;
	}
}

void ReliabilityLayer::FreeThreadedMemory()
{
}

