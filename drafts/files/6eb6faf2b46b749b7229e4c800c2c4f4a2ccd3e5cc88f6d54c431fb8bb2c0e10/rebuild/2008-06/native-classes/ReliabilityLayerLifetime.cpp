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
static const int DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE=512;
static const RakNetTimeNS STARTING_TIME_BETWEEN_PACKETS=100000;
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

void ReliabilityLayer::InitializeVariables( void )
{
	memset( waitingForOrderedPacketReadIndex, 0, NUMBER_OF_ORDERED_STREAMS * sizeof(OrderingIndexType));
	memset( waitingForSequencedPacketReadIndex, 0, NUMBER_OF_ORDERED_STREAMS * sizeof(OrderingIndexType) );
	memset( waitingForOrderedPacketWriteIndex, 0, NUMBER_OF_ORDERED_STREAMS * sizeof(OrderingIndexType) );
	memset( waitingForSequencedPacketWriteIndex, 0, NUMBER_OF_ORDERED_STREAMS * sizeof(OrderingIndexType) );
	memset( &statistics, 0, sizeof( statistics ) );
	statistics.connectionStartTime = RakNet::GetTime();
	splitPacketId = 0;
	throughputCapCountdown = 0;
	sendMessageNumberIndex = 0;
	lastUpdateTime = RakNet::GetTimeNS();
	lastTimeBetweenPacketsIncrease = lastTimeBetweenPacketsDecrease = lastUpdateTime;
	nextAllowedThroughputSample = 0;
	deadConnection = cheater = false;
	lastAckTime = 0;
	ackPing = 0;
	receivedPacketsBaseIndex = 0;
	sendPacketCount = receivePacketCount = 0;
	resetReceivedPackets = true;
	timeBetweenPackets = STARTING_TIME_BETWEEN_PACKETS;
	ackPingSum = 0;
	ackPingCount = 0;
	nextSendTime = 0;
	continuousSend = false;
	histogramStart = 0;
	histogramBitsSent = 0;
}


void ReliabilityLayer::FreeThreadSafeMemory( void )
{
	unsigned i,j;
	InternalPacket *internalPacket;

	for (i=0; i < splitPacketChannelList.Size(); i++)
	{
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			delete [] splitPacketChannelList[i]->splitPacketList[j]->data;
		}
		delete splitPacketChannelList[i];
	}
	splitPacketChannelList.Clear();

	while ( outputQueue.Size() > 0 )
	{
		internalPacket = outputQueue.Pop();
		delete [] internalPacket->data;
	}

	outputQueue.ClearAndForceAllocation( 32 );

	for ( i = 0; i < orderingList.Size(); i++ )
	{
		if ( orderingList[ i ] )
		{
			DataStructures::LinkedList<InternalPacket*>* theList = orderingList[ i ];

			if ( theList )
			{
				while ( theList->Size() )
				{
					internalPacket = orderingList[ i ]->Pop();
					delete [] internalPacket->data;
				}

				delete theList;
			}
		}
	}

	orderingList.Clear();

	//resendList.ForEachData(DeleteInternalPacket);
	resendList.Clear();
	while ( resendQueue.Size() )
	{
		// The resend Queue can have NULL pointer holes.  This is so we can deallocate blocks without having to compress the array
		internalPacket = resendQueue.Pop();

		if ( internalPacket )
		{
			delete [] internalPacket->data;
		}
	}
	resendQueue.ClearAndForceAllocation( DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE );


	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		j = 0;
		for ( ; j < sendPacketSet[ i ].Size(); j++ )
		{
		delete [] ( sendPacketSet[ i ] ) [ j ]->data;
		}

		sendPacketSet[ i ].ClearAndForceAllocation( 32 ); // Preallocate the send lists so we don't do a bunch of reallocations unnecessarily
	}

	for (unsigned i = 0; i < delayList.Size(); i++ )
		delete delayList[ i ];
	delayList.Clear();

	internalPacketPool.Clear();

	//messageHistogram.Clear();

	acknowlegements.Clear();
}



void ReliabilityLayer::Reset( bool resetVariables )
{
	FreeMemory( true ); // true because making a memory reset pending in the update cycle causes resets after reconnects.  Instead, just call Reset from a single thread
	if (resetVariables)
		InitializeVariables();
}


void ReliabilityLayer::SetEncryptionKey( const unsigned char* key )
{
	if ( key )
		encryptor.SetKey( key );
	else
		encryptor.UnsetKey();
}


void ReliabilityLayer::SetTimeoutTime( RakNetTime time )
{
	timeoutTime=time;
}


void ReliabilityLayer::SendBitStream( SOCKET s, SystemAddress systemAddress, RakNet::BitStream *bitStream )
{
	// SHOW - showing reliable flow
	// if (bitStream->GetNumberOfBytesUsed()>50)
	//  printf("Sending %i bytes. sendQueue[0].Size()=%i, resendList.Size()=%i\n", bitStream->GetNumberOfBytesUsed(), sendQueue[0].Size(),resendList.Size());

	int oldLength, length;

	// sentFrames++;

	// Encode the whole bitstream if the encoder is defined.

	if ( encryptor.IsKeySet() )
	{
		length = bitStream->GetNumberOfBytesUsed();
		oldLength = length;

		encryptor.Encrypt( ( unsigned char* ) bitStream->GetData(), length, ( unsigned char* ) bitStream->GetData(), &length );
		statistics.encryptionBitsSent = ( length - oldLength ) * 8;

		assert( ( length % 16 ) == 0 );
	}
	else
	{
		length = bitStream->GetNumberOfBytesUsed();
	}

	statistics.packetsSent++;
	statistics.totalBitsSent += length * 8;
	histogramBitsSent += length * 8;
	//printf("total bits=%i length=%i\n", BITS_TO_BYTES(statistics.totalBitsSent), length);

	SocketLayer::Instance()->SendTo( s, ( char* ) bitStream->GetData(), length, systemAddress.binaryAddress, systemAddress.port );

	// lastPacketSendTime=time;
}


void ReliabilityLayer::ApplyNetworkSimulator( double _maxSendBPS, RakNetTime _minExtraPing, RakNetTime _extraPingVariance )
{

	maxSendBPS=_maxSendBPS;
	minExtraPing=_minExtraPing;
	extraPingVariance=_extraPingVariance;

}


