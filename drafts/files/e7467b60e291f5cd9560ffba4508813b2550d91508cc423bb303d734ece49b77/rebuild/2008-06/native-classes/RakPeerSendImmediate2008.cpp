// native-flags: /O2 /GS- /EHsc /MD /U_RELEASE /FImalloc.h /I{headers}/../../../tools/openrbx/Client/Network/raknet30/Source /I{headers}/../../../tools/openrbx/util
// 2008 native headers, with simulator fields; complete ABI and runtime unverified.
#include <malloc.h>
#define alloca _malloca
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

#include "RakNetDefines.h"
#include "../native-headers/RakPeer.h"
#include "RakNetTypes.h"

#ifdef _WIN32
//#include <Shlwapi.h>
#include <process.h>
#else
#define closesocket close
#include <unistd.h>
#include <pthread.h>
#endif
#include <ctype.h> // toupper
#include <string.h>
#include "GetTime.h"
#include "MessageIdentifiers.h"
#include "DS_HuffmanEncodingTree.h"
#include "Rand.h"
#include "PluginInterface.h"
#include "StringCompressor.h"
#include "StringTable.h"
#include "NetworkIDManager.h"
#include "RakNetTypes.h"
#include "SHA1.h"
#include "RakSleep.h"
#include "RouterInterface.h"
#include "RakAssert.h"

#if !defined ( __APPLE__ ) && !defined ( __APPLE_CC__ )
#include <malloc.h>
#endif

#ifdef _COMPATIBILITY_1
//
#elif defined(_WIN32)
//
#elif defined(_COMPATIBILITY_2)
#include "Compatibility2Includes.h"
#include <stdlib.h>
#else
#include <stdlib.h>
#endif

#ifdef _MSC_VER
#pragma warning( push )
#endif

#ifdef _WIN32
unsigned __stdcall UpdateNetworkLoop( LPVOID arguments );
#else
void* UpdateNetworkLoop( void* arguments );
#endif

bool RakPeer::SendImmediate( char *data, int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, SystemAddress systemAddress, bool broadcast, bool useCallerDataAllocation, RakNetTimeNS currentTime )
{
	unsigned *sendList;
	unsigned sendListSize;
	bool callerDataAllocationUsed;
	unsigned remoteSystemIndex, sendListIndex; // Iterates into the list of remote systems
	unsigned numberOfBytesUsed = BITS_TO_BYTES(numberOfBitsToSend);
	callerDataAllocationUsed=false;

	sendListSize=0;

	// 03/06/06 - If broadcast is false, use the optimized version of GetIndexFromSystemAddress
	if (broadcast==false)
	{
#if !defined(_COMPATIBILITY_1)
		sendList=(unsigned *)alloca(sizeof(unsigned));
#else
		sendList = new unsigned[1];
#endif
		remoteSystemIndex=GetIndexFromSystemAddress( systemAddress, true );
		if (remoteSystemIndex!=(unsigned)-1 &&
			remoteSystemList[remoteSystemIndex].isActive &&
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ASAP && 
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ASAP_SILENTLY && 
			remoteSystemList[remoteSystemIndex].connectMode!=RemoteSystemStruct::DISCONNECT_ON_NO_ACK)
		{
			sendList[0]=remoteSystemIndex;
			sendListSize=1;
		}
	}
	else
	{
#if !defined(_COMPATIBILITY_1)
	//sendList=(unsigned *)alloca(sizeof(unsigned)*remoteSystemListSize);
		sendList=(unsigned *)alloca(sizeof(unsigned)*maximumNumberOfPeers);
#else
	//sendList = new unsigned[remoteSystemListSize];
		sendList = new unsigned[maximumNumberOfPeers];
#endif

		// remoteSystemList in network thread
		for ( remoteSystemIndex = 0; remoteSystemIndex < maximumNumberOfPeers; remoteSystemIndex++ )
		//for ( remoteSystemIndex = 0; remoteSystemIndex < remoteSystemListSize; remoteSystemIndex++ )
		{
			if ( remoteSystemList[ remoteSystemIndex ].isActive && remoteSystemList[ remoteSystemIndex ].systemAddress != systemAddress && remoteSystemList[ remoteSystemIndex ].systemAddress != UNASSIGNED_SYSTEM_ADDRESS )
				sendList[sendListSize++]=remoteSystemIndex;
		}
	}

	if (sendListSize==0)
	{
#if defined(_COMPATIBILITY_1)
		delete [] sendList;
#endif
		return false;
	}

	for (sendListIndex=0; sendListIndex < sendListSize; sendListIndex++)
	{
		if ( trackFrequencyTable )
		{
			unsigned i;
			// Store output frequency
			for (i=0 ; i < numberOfBytesUsed; i++ )
				frequencyTable[ (unsigned char)(data[i]) ]++;
			rawBytesSent += numberOfBytesUsed;
		}

		if ( outputTree )
		{
			RakNet::BitStream bitStreamCopy( numberOfBytesUsed );
			outputTree->EncodeArray( (unsigned char*) data, numberOfBytesUsed, &bitStreamCopy );
			compressedBytesSent += bitStreamCopy.GetNumberOfBytesUsed();
			remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send( (char*) bitStreamCopy.GetData(), bitStreamCopy.GetNumberOfBitsUsed(), priority, reliability, orderingChannel, true, remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime );
		}
		else
		{
			// Send may split the packet and thus deallocate data.  Don't assume data is valid if we use the callerAllocationData
			bool useData = useCallerDataAllocation && callerDataAllocationUsed==false && sendListIndex+1==sendListSize;
			remoteSystemList[sendList[sendListIndex]].reliabilityLayer.Send( data, numberOfBitsToSend, priority, reliability, orderingChannel, useData==false, remoteSystemList[sendList[sendListIndex]].MTUSize, currentTime );
			if (useData)
				callerDataAllocationUsed=true;
		}

		if (reliability==RELIABLE || reliability==RELIABLE_ORDERED || reliability==RELIABLE_SEQUENCED)
			remoteSystemList[sendList[sendListIndex]].lastReliableSend=(RakNetTime)(currentTime/(RakNetTimeNS)1000);
	}

#if defined(_COMPATIBILITY_1)
	delete [] sendList;
#endif

	// Return value only meaningful if true was passed for useCallerDataAllocation.  Means the reliability layer used that data copy, so the caller should not deallocate it
	return callerDataAllocationUsed;
}
