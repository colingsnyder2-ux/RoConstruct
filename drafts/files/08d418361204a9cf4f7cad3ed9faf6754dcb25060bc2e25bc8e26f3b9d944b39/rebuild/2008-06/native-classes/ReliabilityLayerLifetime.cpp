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



bool ReliabilityLayer::HandleSocketReceiveFromConnectedPlayer( const char *buffer, int length, SystemAddress systemAddress, DataStructures::List<PluginInterface*> &messageHandlerList, int MTUSize )
{
#ifdef _DEBUG
	assert( !( length <= 0 || buffer == 0 ) );
#endif

	if ( length <= 2 || buffer == 0 )
		return true;

	//int numberOfAcksInFrame = 0;
	RakNetTimeNS time;
	bool indexFound;
	int count, size;
	MessageNumberType holeCount;
	unsigned i;
	bool hasAcks=false;

//	bool duplicatePacket;

	// bytesReceived+=length + UDP_HEADER_SIZE;

	UpdateThreadedMemory();

	// decode this whole chunk if the decoder is defined.
	if ( encryptor.IsKeySet() )
	{
		if ( encryptor.Decrypt( ( unsigned char* ) buffer, length, ( unsigned char* ) buffer, &length ) == false )
		{
			statistics.bitsWithBadCRCReceived += length * 8;
			statistics.packetsWithBadCRCReceived++;
			return false;
		}
	}

	statistics.bitsReceived += length * 8;
	statistics.packetsReceived++;

	RakNet::BitStream socketData( (unsigned char*) buffer, length, false ); // Convert the incoming data to a bitstream for easy parsing
	time = RakNet::GetTimeNS();

	DataStructures::RangeList<MessageNumberType> incomingAcks;
	socketData.Read(hasAcks);
	if (hasAcks)
	{
		MessageNumberType messageNumber;
		RakNetTime ourSystemTime;
		socketData.Read(ourSystemTime);
		if (incomingAcks.Deserialize(&socketData)==false)
			return false;
		for (i=0; i<incomingAcks.ranges.Size();i++)
		{
			if (incomingAcks.ranges[i].minIndex>incomingAcks.ranges[i].maxIndex)
			{
				RakAssert(incomingAcks.ranges[i].minIndex<=incomingAcks.ranges[i].maxIndex);
				return false;
			}

			for (messageNumber=incomingAcks.ranges[i].minIndex; messageNumber >= incomingAcks.ranges[i].minIndex && messageNumber <= incomingAcks.ranges[i].maxIndex; messageNumber++)
			{
				hasAcks=true;

				InternalPacket *internalPacket;
				if (resendList.Delete(messageNumber, internalPacket))
					internalPacket->nextActionTime=0;
				else
					statistics.duplicateAcknowlegementsReceived++;

				if ( resendList.IsEmpty() )
				{
					lastAckTime = 0; // Not resending anything so clear this var so we don't drop the connection on not getting any more acks
				}
				else
				{
					lastAckTime = time; // Just got an ack.  Record when we got it so we know the connection is alive
				}
			}
		}

		ackPing = time - (RakNetTimeNS)ourSystemTime * (RakNetTimeNS)1000;

		RakNetTimeNS avePing;
		if (ackPingCount!=0)
			avePing = ackPingSum / ackPingCount;
		else
			avePing = ackPing;

		if (continuousSend && time >= nextAllowedThroughputSample)
		{
			if (ackPing <= avePing*6/5 + 1000)
			{
				RakNetTimeNS timeDecrement = (RakNetTimeNS) ceil((long double)timeBetweenPackets * .02);
				if (timeDecrement < timeBetweenPackets)
				{
					nextSendTime -= timeDecrement;
					timeBetweenPackets -= timeDecrement;
				}

				ackPingSum += ackPing;
				ackPingCount++;
				lastTimeBetweenPacketsDecrease = time;
			}
			else
			{
				RakNetTimeNS timeIncrement = (RakNetTimeNS) ceil((long double)timeBetweenPackets * .04);
				nextSendTime += timeIncrement;
				lastTimeBetweenPacketsIncrease = time;
				timeBetweenPackets += timeIncrement;
				if (timeBetweenPackets > 100000)
				{
					timeBetweenPackets = 100000;
					ackPingSum = 1000000;
					ackPingCount = 1;
				}
			}

			nextAllowedThroughputSample = time + ackPing;
		}
	}

	bool hasRemoteSystemTime;
	socketData.Read(hasRemoteSystemTime);
	if (hasRemoteSystemTime)
		socketData.Read(remoteSystemTime);

	// Parse the bitstream to create an internal packet
	InternalPacket* internalPacket = CreateInternalPacketFromBitStream( &socketData, time );

	if (internalPacket==0)
		return hasAcks;

	while ( internalPacket )
	{
		for (i=0; i < messageHandlerList.Size(); i++)
			messageHandlerList[i]->OnInternalPacket(internalPacket, receivePacketCount, systemAddress, (RakNetTime)(time/(RakNetTimeNS)1000), false);

		{
#ifdef _DEBUG_LOGGER
			{
				char temp[256];
				sprintf(temp, "%p: Got packet %i data: %i bitlen: %i\n", this, internalPacket->messageNumber, (unsigned char) internalPacket->data[0], internalPacket->dataBitLength);
				OutputDebugStr(temp);
			}
#endif

			// resetReceivedPackets is set from a non-threadsafe function.
			// We do the actual reset in this function so the data is not modified by multiple threads
			if (resetReceivedPackets)
			{
				hasReceivedPacketQueue.ClearAndForceAllocation(DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE);
				receivedPacketsBaseIndex=0;
				resetReceivedPackets=false;
			}

			// If the following conditional is true then this either a duplicate packet
			// or an older out of order packet
			// The subtraction unsigned overflow is intentional
			// If the following conditional is true then this either a duplicate packet
			// or an older out of order packet
			// The subtraction unsigned overflow is intentional
			holeCount = (MessageNumberType)(internalPacket->messageNumber-receivedPacketsBaseIndex);

			//   receivedPacketsCount++;
			if ( internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_ORDERED || internalPacket->reliability == RELIABLE )
			{
				SendAcknowledgementPacket( internalPacket->messageNumber, time );
			}
			const MessageNumberType typeRange = (MessageNumberType)-1;

			if (holeCount==0)
			{
				// Got what we were expecting
				if (hasReceivedPacketQueue.Size())
					hasReceivedPacketQueue.Pop();
				++receivedPacketsBaseIndex;
			}
			else if (holeCount > typeRange-typeRange/2)
			{
				// Underflow - got a packet we have already counted past
				statistics.duplicateMessagesReceived++;

				// Duplicate packet
				delete [] internalPacket->data;
				internalPacketPool.Release( internalPacket );
				goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
			}
			else if (holeCount<hasReceivedPacketQueue.Size())
			{
				// Got a higher count out of order packet that was missing in the sequence or we already got
				if (hasReceivedPacketQueue[holeCount]!=0) // non-zero means this is a hole
				{
					// Fill in the hole
					hasReceivedPacketQueue[holeCount]=0; // We got the packet at holeCount
				}
				else
				{
					// Not a hole - just a duplicate packet
					statistics.duplicateMessagesReceived++;

					// Duplicate packet
					delete [] internalPacket->data;
					internalPacketPool.Release( internalPacket );
					goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
				}
			}
			else // holeCount>=receivedPackets.Size()
			{
				// Got a higher count out of order packet whose messageNumber is higher than we have ever got

				// Add 0 times to the queue until (messageNumber - baseIndex) < queue size.
				while ((MessageNumberType)(holeCount) > hasReceivedPacketQueue.Size())
					hasReceivedPacketQueue.Push(time+(RakNetTimeNS)60000000);
				hasReceivedPacketQueue.Push(0); // Got the packet
#ifdef _DEBUG
				// If this assert hits then MessageNumberType has overflowed
				assert(hasReceivedPacketQueue.Size() < (unsigned int)((MessageNumberType)(-1)));
#endif
			}

			// Pop all expired times.  0 means we got the packet, in which case we don't track this index either.
			while ( hasReceivedPacketQueue.Size()>0 && hasReceivedPacketQueue.Peek() < time )
			{
				hasReceivedPacketQueue.Pop();
				++receivedPacketsBaseIndex;
			}

			statistics.messagesReceived++;

			// If the allocated buffer is > DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE and it is 3x greater than the number of elements actually being used
			if (hasReceivedPacketQueue.AllocationSize() > (unsigned int) DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE && hasReceivedPacketQueue.AllocationSize() > hasReceivedPacketQueue.Size() * 3)
				hasReceivedPacketQueue.Compress();

			// Keep on top of deleting old unreliable split packets so they don't clog the list.
			if ( internalPacket->splitPacketCount > 0 )
				DeleteOldUnreliableSplitPackets( time );

			if ( internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == UNRELIABLE_SEQUENCED )
			{
#ifdef _DEBUG
				assert( internalPacket->orderingChannel < NUMBER_OF_ORDERED_STREAMS );
#endif

				if ( internalPacket->orderingChannel >= NUMBER_OF_ORDERED_STREAMS )
				{
					// Invalid packet
#ifdef _DEBUG
					printf( "Got invalid packet\n" );
#endif

					delete [] internalPacket->data;
					internalPacketPool.Release( internalPacket );
					goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
				}

				if ( IsOlderOrderedPacket( internalPacket->orderingIndex, waitingForSequencedPacketReadIndex[ internalPacket->orderingChannel ] ) == false )
				{
					statistics.sequencedMessagesInOrder++;


					// Is this a split packet?
					if ( internalPacket->splitPacketCount > 0 )
					{
						// Generate the split
						// Verify some parameters to make sure we don't get junk data


						// Check for a rebuilt packet
						InsertIntoSplitPacketList( internalPacket, time );

						// Sequenced
						internalPacket = BuildPacketFromSplitPacketList( internalPacket->splitPacketId, time );

						if ( internalPacket )
						{
							// Update our index to the newest packet
							waitingForSequencedPacketReadIndex[ internalPacket->orderingChannel ] = internalPacket->orderingIndex + 1;

							// If there is a rebuilt packet, add it to the output queue
							outputQueue.Push( internalPacket );
							internalPacket = 0;
						}

						// else don't have all the parts yet
					}

					else
					{
						// Update our index to the newest packet
						waitingForSequencedPacketReadIndex[ internalPacket->orderingChannel ] = internalPacket->orderingIndex + 1;

						// Not a split packet. Add the packet to the output queue
						outputQueue.Push( internalPacket );
						internalPacket = 0;
					}
				}
				else
				{
					statistics.sequencedMessagesOutOfOrder++;

					// Older sequenced packet. Discard it
					delete [] internalPacket->data;
					internalPacketPool.Release( internalPacket );
				}

				goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
			}

			// Is this an unsequenced split packet?
			if ( internalPacket->splitPacketCount > 0 )
			{
				// An unsequenced split packet.  May be ordered though.

				// Check for a rebuilt packet
				if ( internalPacket->reliability != RELIABLE_ORDERED )
					internalPacket->orderingChannel = 255; // Use 255 to designate not sequenced and not ordered

				InsertIntoSplitPacketList( internalPacket, time );

				internalPacket = BuildPacketFromSplitPacketList( internalPacket->splitPacketId, time );

				if ( internalPacket == 0 )
				{

					// Don't have all the parts yet
					goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
				}

				// else continue down to handle RELIABLE_ORDERED
			}

			if ( internalPacket->reliability == RELIABLE_ORDERED )
			{
#ifdef _DEBUG
				assert( internalPacket->orderingChannel < NUMBER_OF_ORDERED_STREAMS );
#endif

				if ( internalPacket->orderingChannel >= NUMBER_OF_ORDERED_STREAMS )
				{
#ifdef _DEBUG
					printf("Got invalid ordering channel %i from packet %i\n", internalPacket->orderingChannel, internalPacket->messageNumber);
#endif
					// Invalid packet
					delete [] internalPacket->data;
					internalPacketPool.Release( internalPacket );
					goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
				}

				if ( waitingForOrderedPacketReadIndex[ internalPacket->orderingChannel ] == internalPacket->orderingIndex )
				{
					// Get the list to hold ordered packets for this stream
					DataStructures::LinkedList<InternalPacket*> *orderingListAtOrderingStream;
					unsigned char orderingChannelCopy = internalPacket->orderingChannel;

					statistics.orderedMessagesInOrder++;

					// Show ordering index increment
					//printf("Pushing immediate packet %i with ordering index %i\n", internalPacket->messageNumber, internalPacket->orderingIndex );

					// Push the packet for the user to read
					outputQueue.Push( internalPacket );
					internalPacket = 0; // Don't reference this any longer since other threads access it

					// Wait for the next ordered packet in sequence
					waitingForOrderedPacketReadIndex[ orderingChannelCopy ] ++; // This wraps

					orderingListAtOrderingStream = GetOrderingListAtOrderingStream( orderingChannelCopy );

					if ( orderingListAtOrderingStream != 0)
					{
						while ( orderingListAtOrderingStream->Size() > 0 )
						{
							// Cycle through the list until nothing is found
							orderingListAtOrderingStream->Beginning();
							indexFound=false;
							size=orderingListAtOrderingStream->Size();
							count=0;

							while (count++ < size)
							{
								if ( orderingListAtOrderingStream->Peek()->orderingIndex == waitingForOrderedPacketReadIndex[ orderingChannelCopy ] )
								{
									/*
									RakNet::BitStream temp(orderingListAtOrderingStream->Peek()->data, BITS_TO_BYTES(orderingListAtOrderingStream->Peek()->dataBitLength), false);
									temp.IgnoreBits(8);
									unsigned int receivedPacketNumber=0;
									temp.Read(receivedPacketNumber);
									printf("Receive: receivedPacketNumber=%i orderingIndex=%i waitingFor=%i\n", receivedPacketNumber, orderingListAtOrderingStream->Peek()->orderingIndex, waitingForOrderedPacketReadIndex[ orderingChannelCopy ]);
									*/

									//printf("Pushing delayed packet %i with ordering index %i. outputQueue.Size()==%i\n", orderingListAtOrderingStream->Peek()->messageNumber, orderingListAtOrderingStream->Peek()->orderingIndex, outputQueue.Size() );
									outputQueue.Push( orderingListAtOrderingStream->Pop() );
									waitingForOrderedPacketReadIndex[ orderingChannelCopy ]++; // This wraps at 255
									indexFound=true;
								}
								else
									(*orderingListAtOrderingStream)++;
							}

							if (indexFound==false)
								break;
						}
					}

					internalPacket = 0;
				}
				else
				{
				//	assert(waitingForOrderedPacketReadIndex[ internalPacket->orderingChannel ] < internalPacket->orderingIndex);
					statistics.orderedMessagesOutOfOrder++;

					// This is a newer ordered packet than we are waiting for. Store it for future use
					AddToOrderingList( internalPacket );
				}

				goto CONTINUE_SOCKET_DATA_PARSE_LOOP;
			}

			// Nothing special about this packet.  Add it to the output queue
			outputQueue.Push( internalPacket );

			internalPacket = 0;
		}

		// Used for a goto to jump to the next packet immediately

	CONTINUE_SOCKET_DATA_PARSE_LOOP:
		// Parse the bitstream to create an internal packet
		internalPacket = CreateInternalPacketFromBitStream( &socketData, time );
	}

	/*
	if (numberOfAcksInFrame > 0)
//		if (time > lastWindowAdjustTime+ping)
	{
	//	printf("Window size up\n");
		windowSize+=1 + numberOfAcksInFrame/windowSize;
		if ( windowSize > MAXIMUM_WINDOW_SIZE )
			windowSize = MAXIMUM_WINDOW_SIZE;
		//lastWindowAdjustTime=time;
	}
	//else
	//	printf("No acks in frame\n");
*/
	/*
	// numberOfAcksInFrame>=windowSize means that all the packets we last sent from the resendList are cleared out
	// 11/17/05 - the problem with numberOfAcksInFrame >= windowSize is that if the entire frame is filled with resends but not all resends filled the frame
	// then the sender is limited by how many resends can fit in one frame
	if ( numberOfAcksInFrame >= windowSize && ( sendPacketSet[ SYSTEM_PRIORITY ].Size() > 0 || sendPacketSet[ HIGH_PRIORITY ].Size() > 0 || sendPacketSet[ MEDIUM_PRIORITY ].Size() > 0 ) )
	{
		// reliabilityLayerMutexes[windowSize_MUTEX].Lock();
		//printf("windowSize=%i lossyWindowSize=%i\n", windowSize, lossyWindowSize);

		if ( windowSize < lossyWindowSize || (time>lastWindowIncreaseSizeTime && time-lastWindowIncreaseSizeTime>lostPacketResendDelay*2) )   // Increases the window size slowly, testing for packetloss
		{
			// If we get a frame which clears out the resend queue after handling one or more acks, and we have packets waiting to go out,
			// and we didn't recently lose a packet then increase the window size by 1
			windowSize++;

			if ( (time>lastWindowIncreaseSizeTime && time-lastWindowIncreaseSizeTime>lostPacketResendDelay*2) )   // The increase is to test for packetloss
				lastWindowIncreaseSizeTime = time;

			// If the window is so large that we couldn't possibly fit any more packets into the frame, then just leave it alone
			if ( windowSize > MAXIMUM_WINDOW_SIZE )
				windowSize = MAXIMUM_WINDOW_SIZE;

			// SHOW - WINDOWING
			//else
			//	printf("Increasing windowSize to %i.  Lossy window size = %i\n", windowSize, lossyWindowSize);

			// If we are more than 5 over the lossy window size, increase the lossy window size by 1
			if ( windowSize == MAXIMUM_WINDOW_SIZE || windowSize - lossyWindowSize > 5 )
				lossyWindowSize++;
		}
		// reliabilityLayerMutexes[windowSize_MUTEX].Unlock();
	}
	*/

	if (hasAcks)
	{
		UpdateWindowFromAck(time);
	}

	receivePacketCount++;

	return true;
}


void ReliabilityLayer::UpdateThreadedMemory(void)
{
	if ( freeThreadedMemoryOnNextUpdate )
	{
		freeThreadedMemoryOnNextUpdate = false;
		FreeThreadedMemory();
	}
}


void ReliabilityLayer::Update( SOCKET s, SystemAddress systemAddress, int MTUSize, RakNetTimeNS time, unsigned bitsPerSecondLimit, DataStructures::List<PluginInterface*> &messageHandlerList )
{
	// This line is necessary because the timer isn't accurate
	if (time <= lastUpdateTime)
	{
		// Always set the last time in case of overflow
		lastUpdateTime=time;
		return;
	}

	RakNetTimeNS elapsed = time - lastUpdateTime;
	lastUpdateTime=time;

	// unsigned resendListSize;
	bool reliableDataSent;
	UpdateThreadedMemory();

	// Due to thread vagarities and the way I store the time to avoid slow calls to RakNet::GetTime
	// time may be less than lastAck
	if ( resendList.IsEmpty()==false && AckTimeout(time) )
	{
		// SHOW - dead connection
		// printf("The connection has been lost.\n");
		// We've waited a very long time for a reliable packet to get an ack and it never has
		deadConnection = true;
		return;
	}

	if (time >= histogramStart + (RakNetTimeNS)10000000)
	{
		histogramStart = time;
		histogramBitsSent = 0;

		RakNetTimeNS avePing;
		if (ackPingCount!=0)
			avePing = ackPingSum / ackPingCount;
		else
			avePing = ackPing;
		ackPingSum = avePing * 100;
		ackPingCount = 100;
	}

	// The throughput cap is a countdown in nanoseconds, not a bandwidth accumulator. While it is
	// still positive nothing is sent this update and the connection is marked not-continuous.
	if (bitsPerSecondLimit && throughputCapCountdown > 0)
	{
		throughputCapCountdown -= elapsed;
		if (throughputCapCountdown < 0)
		{
			throughputCapCountdown = 0;
		}
		else
		{
			continuousSend = false;
			goto DO_LAGGED_SENDS;
		}
	}

	if (time >= nextSendTime)
	{
		// One datagram per timeBetweenPackets of elapsed time, capped at a hundred packets'
		// worth so a long stall does not turn into a burst.
		RakNetTimeNS usedTime = 0;
		RakNetTimeNS availableTime = time - nextSendTime;
		if (availableTime > timeBetweenPackets*100)
		{
			availableTime = timeBetweenPackets*100;
			nextSendTime = time;
		}
		while (usedTime < availableTime)
		{
			updateBitStream.Reset();
			if ( GenerateDatagram( &updateBitStream, MTUSize, &reliableDataSent, time, systemAddress, messageHandlerList )==false )
				break;


			if (minExtraPing > 0 || extraPingVariance > 0)
			{
				// Delay the send to simulate lag
				DataAndTime *dt;
				dt = new DataAndTime;
				memcpy( dt->data, updateBitStream.GetData(), updateBitStream.GetNumberOfBytesUsed() );
				dt->length = updateBitStream.GetNumberOfBytesUsed();
				dt->sendTime = time + (RakNetTimeNS)minExtraPing*1000;
				if (extraPingVariance > 0)
					dt->sendTime += ( randomMT() % (int)extraPingVariance );
				delayList.Insert( dt );
			}
			else

			SendBitStream( s, systemAddress, &updateBitStream );

			if (bitsPerSecondLimit > 0)
			{
				throughputCapCountdown += (RakNetTimeNS)((double)updateBitStream.GetNumberOfBitsUsed() * 1000000.0 / (double)bitsPerSecondLimit);
				if (throughputCapCountdown > 30000)
					break;
			}

			usedTime += timeBetweenPackets;
		}

		nextSendTime += usedTime;

		// The send loop ran to completion, so there is more waiting than the window allows.
		if (usedTime >= availableTime)
			continuousSend = true;
		else
			continuousSend = false;
	}
	else if (acknowlegements.Size() > 0)
	{
		// Nothing to send yet, but acks should not wait for the next send window.
		updateBitStream.Reset();
		updateBitStream.Write1();
		updateBitStream.Write(remoteSystemTime);
		statistics.acknowlegementBitsSent += acknowlegements.Serialize(&updateBitStream, (MTUSize-UDP_HEADER_SIZE)*8-1, true);
		SendBitStream( s, systemAddress, &updateBitStream );

		if (bitsPerSecondLimit > 0)
			throughputCapCountdown += (RakNetTimeNS)((double)updateBitStream.GetNumberOfBitsUsed() * 1000000.0 / (double)bitsPerSecondLimit);
	}

DO_LAGGED_SENDS:
	;

	// Do any lagged sends
	unsigned i = 0;
	while ( i < delayList.Size() )
	{
		if ( delayList[ i ]->sendTime < time )
		{
			updateBitStream.Reset();
			updateBitStream.Write( delayList[ i ]->data, delayList[ i ]->length );
			// Send it now
			SendBitStream( s, systemAddress, &updateBitStream );

			delete delayList[ i ];
			if (i != delayList.Size() - 1)
				delayList[ i ] = delayList[ delayList.Size() - 1 ];
			delayList.RemoveFromEnd();
		}

		else
			i++;
	}


}


bool ReliabilityLayer::GenerateDatagram( RakNet::BitStream *output, int MTUSize, bool *reliableDataSent, RakNetTimeNS time, SystemAddress systemAddress, DataStructures::List<PluginInterface*> &messageHandlerList  )
{
	InternalPacket * internalPacket;
//	InternalPacket *temp;
	int maxDataBitSize;
	int reliableBits = 0;
	int nextPacketBitLength;
	unsigned i, messageHandlerIndex;
	bool isReliable, onlySendUnreliable;
	bool wroteData;
	bool wroteAcks;
	unsigned messagesSent=0;

	maxDataBitSize = MTUSize - UDP_HEADER_SIZE;

	if ( encryptor.IsKeySet() )
		maxDataBitSize -= 16; // Extra data for the encryptor

	maxDataBitSize <<= 3;

	*reliableDataSent = false;

	if (acknowlegements.Size()>0)
	{
		output->Write(true);
		output->Write(remoteSystemTime);
		messagesSent++;
		wroteAcks=true;
		statistics.acknowlegementBitsSent +=acknowlegements.Serialize(output, (MTUSize-UDP_HEADER_SIZE)*8-1, true);
	}
	else
	{
		wroteAcks=false;
		output->Write(false);
	}
	wroteData=false;

	while ( resendQueue.Size() > 0 )
	{
		internalPacket = resendQueue.Peek();
		// The resend Queue can have holes.  This is so we can deallocate blocks without having to compress the array
		if ( internalPacket->nextActionTime == 0 )
		{
			resendQueue.Pop();
			delete [] internalPacket->data;
			internalPacketPool.Release( internalPacket );
			continue; // This was a hole
		}

		if ( resendQueue.Peek()->nextActionTime < time )
		{
			internalPacket = resendQueue.Pop();

			nextPacketBitLength = GetBitStreamHeaderLength( internalPacket ) + internalPacket->dataBitLength;

			if ( output->GetNumberOfBitsUsed() + nextPacketBitLength > maxDataBitSize )
			{
				resendQueue.PushAtHead( internalPacket ); // Not enough room to use this packet after all!

				goto END_OF_GENERATE_FRAME;
			}

			RakAssert(internalPacket->priority >= 0);

#ifdef _DEBUG_LOGGER
			{
				char temp[256];
				sprintf(temp, "%p: Resending packet %i data: %i bitlen: %i\n", this, internalPacket->messageNumber, (unsigned char) internalPacket->data[0], internalPacket->dataBitLength);
				OutputDebugStr(temp);
			}
#endif

			for (messageHandlerIndex=0; messageHandlerIndex < messageHandlerList.Size(); messageHandlerIndex++)
				messageHandlerList[messageHandlerIndex]->OnInternalPacket(internalPacket, sendPacketCount, systemAddress, (RakNetTime)(time/(RakNetTimeNS)1000), true);

			// Write to the output bitstream
			statistics.messageResends++;
			statistics.messageDataBitsResent += internalPacket->dataBitLength;

			if (wroteData==false)
			{
				wroteData=true;
				output->Write(true);
				output->Write((RakNetTime)(time/(RakNetTimeNS)1000));
			}
			statistics.messagesTotalBitsResent += WriteToBitStreamFromInternalPacket( output, internalPacket, time );
			internalPacket->packetNumber=sendPacketCount;
			messagesSent++;

			*reliableDataSent = true;

			statistics.packetsContainingOnlyAcknowlegementsAndResends++;

			internalPacket->nextActionTime = time + (timeBetweenPackets + 100000) * 3;


			//printf("PACKETLOSS\n ");

			// Put the packet back into the resend list at the correct spot
			// Don't make a copy since I'm reinserting an allocated struct
			InsertPacketIntoResendList( internalPacket, time, false, false );

		}
		else
		{
			break;
		}
	}


	onlySendUnreliable = false;


	// From highest to lowest priority, fill up the output bitstream from the send lists
	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		while ( sendPacketSet[ i ].Size() )
		{
			internalPacket = sendPacketSet[ i ].Pop();

			nextPacketBitLength = GetBitStreamHeaderLength( internalPacket ) + internalPacket->dataBitLength;

			if (unreliableTimeout!=0 &&
				(internalPacket->reliability==UNRELIABLE || internalPacket->reliability==UNRELIABLE_SEQUENCED) &&
				time > internalPacket->creationTime+(RakNetTimeNS)unreliableTimeout)
			{
				// Unreliable packets are deleted
				delete [] internalPacket->data;
				internalPacketPool.Release( internalPacket );
				continue;
			}


			if ( output->GetNumberOfBitsUsed() + nextPacketBitLength > maxDataBitSize )
			{
				// This output won't fit.
				sendPacketSet[ i ].PushAtHead( internalPacket ); // Push this back at the head so it is the next thing to go out
				break;
			}

			if ( internalPacket->reliability == RELIABLE || internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_ORDERED )
				isReliable = true;
			else
				isReliable = false;

			// Write to the output bitstream
			statistics.messagesSent[ i ] ++;
			statistics.messageDataBitsSent[ i ] += internalPacket->dataBitLength;

#ifdef _DEBUG_LOGGER
			{
				char temp[256];
				sprintf(temp, "%p: Sending packet %i data: %i bitlen: %i\n", this, internalPacket->messageNumber, (unsigned char) internalPacket->data[0], internalPacket->dataBitLength);
				OutputDebugStr(temp);
			}
#endif

			for (messageHandlerIndex=0; messageHandlerIndex < messageHandlerList.Size(); messageHandlerIndex++)
				messageHandlerList[messageHandlerIndex]->OnInternalPacket(internalPacket, sendPacketCount, systemAddress, (RakNetTime)(time/(RakNetTimeNS)1000), true);

			if (wroteData==false)
			{
				wroteData=true;
				output->Write(true);
				output->Write((RakNetTime)(time/(RakNetTimeNS)1000));
			}
			internalPacket->messageNumberAssigned=true;
			internalPacket->messageNumber=sendMessageNumberIndex;
			sendMessageNumberIndex++;
			statistics.messageTotalBitsSent[ i ] += WriteToBitStreamFromInternalPacket( output, internalPacket, time );
			//output->PrintBits();
			internalPacket->packetNumber=sendPacketCount;
			messagesSent++;

			if ( isReliable )
			{
				// Reliable packets are saved to resend later
				reliableBits += internalPacket->dataBitLength;
				internalPacket->nextActionTime = time + (timeBetweenPackets + 100000) * 3;
				resendList.Insert( internalPacket->messageNumber, internalPacket);
				//printf("ackTimeIncrement=%i\n", ackTimeIncrement/1000);
				InsertPacketIntoResendList( internalPacket, time, false, true);
				*reliableDataSent = true;
			}
			else
			{
				// Unreliable packets are deleted
				delete [] internalPacket->data;
				internalPacketPool.Release( internalPacket );
			}
		}
	}

END_OF_GENERATE_FRAME:
	;

	// if (output->GetNumberOfBitsUsed()>0)
	// {
	// Update the throttle with the header
	//  bytesSent+=output->GetNumberOfBytesUsed() + UDP_HEADER_SIZE;
	//}

	if (wroteData==false)
		output->Write(false);

	if (wroteAcks || wroteData)
		sendPacketCount++;

	return wroteAcks || wroteData;
}

// FUNCTION: WEBSERVICE 0x101bda40
// FUNCTION: ROBLOX 0x004e3a30
bool ReliabilityLayer::AreAcksWaiting(void)
{
	return acknowlegements.Size() > 0;
}






