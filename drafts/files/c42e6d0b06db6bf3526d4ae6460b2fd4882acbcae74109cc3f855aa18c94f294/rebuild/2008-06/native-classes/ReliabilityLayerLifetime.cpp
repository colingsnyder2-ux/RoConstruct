// >>> native-status (generated) -- do not edit >>>
// ReliabilityLayerLifetime | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto
// <<< native-status | src de8cad86 | roc native-status --write
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
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

#include "../native-headers/ReliabilityLayer.h"
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class DataStructures::MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >;
template class DataStructures::MemoryPool<InternalPacket>;
template class DataStructures::Queue<DataStructures::Page<unsigned int,InternalPacket *,32> *>;
template class DataStructures::Queue<__int64>;
template class DataStructures::RangeNode<unsigned int>;
