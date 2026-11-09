// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp

// Candidate translation unit (score above; library headers required).
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

static const int DEFAULT_HAS_RECEIVED_PACKET_QUEUE_SIZE=512;
static const float PACKETLOSS_TOLERANCE=.02f; // What percentile packetloss we are willing to accept as background noise.
static const double MINIMUM_SEND_BPS=14400.0; // Won't go below this send rate
static const double STARTING_SEND_BPS=28800.0; // What send rate to start at.
static const RakNetTimeNS TIME_TO_NEW_SAMPLE=500000; // How many ns to wait before starting a new sample.  This way buffers have time to overflow or relax at the new send rate, if they are indeed going to overflow.
static const RakNetTimeNS MAX_TIME_TO_SAMPLE=250000; // How many ns to sample the connection before deciding on a course of action(increase or decrease throughput). You must be at full send rate the whole time

#ifdef _MSC_VER
#pragma warning( push )
#endif

#ifdef _WIN32
	//#define _DEBUG_LOGGER
	#ifdef _DEBUG_LOGGER
	#include <windows.h>
	#endif
#endif

// FUNCTION: WEBSERVICE 0x101bcbd0
int SplitPacketChannelComp( SplitPacketIdType const &key, SplitPacketChannel* const &data )
{
	if (key < data->splitPacketList[0]->splitPacketId)
		return -1;
	if (key == data->splitPacketList[0]->splitPacketId)
		return 0;
	return 1;
}

// FUNCTION: WEBSERVICE 0x101bc140
RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsIncrease(void) const
{
	return lastTimeBetweenPacketsIncrease;
}

// FUNCTION: WEBSERVICE 0x101bc130
RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsDecrease(void) const
{
	return lastTimeBetweenPacketsDecrease;
}

// FUNCTION: WEBSERVICE 0x101bc150
RakNetTimeNS ReliabilityLayer::GetAckPing(void) const
{
	return ackPing;
}

// FUNCTION: WEBSERVICE 0x101bc0d0
bool ReliabilityLayer::AckTimeout( RakNetTimeNS curTime )
{
	return curTime > lastAckTime && lastAckTime && curTime - lastAckTime > (RakNetTimeNS) timeoutTime * 1000;
}

// FUNCTION: WEBSERVICE 0x101bd9f0
bool ReliabilityLayer::IsOutgoingDataWaiting(void)
{
	unsigned i;
	for (i=0; i < NUMBER_OF_PRIORITIES; i++)
	{
		if (sendPacketSet[i].Size()>0)
			return true;
	}

	return acknowlegements.Size() > 0 || resendList.IsEmpty()==false;
}

// FUNCTION: WEBSERVICE 0x101bbde0
int SplitPacketIndexComp( SplitPacketIndexType const &key, InternalPacket* const &data )
{
	if (key < data->splitPacketIndex)
		return -1;
	if (key == data->splitPacketIndex)
		return 0;
	return 1;
}


//-------------------------------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------------------------------
// Add 21 to the default MTU so if we encrypt it can hold potentially 21 more bytes of extra data + padding.
// FUNCTION: WEBSERVICE 0x101bfaa0
ReliabilityLayer::ReliabilityLayer() : updateBitStream( DEFAULT_MTU_SIZE + 21 )   // preallocate the update bitstream so we can avoid a lot of reallocs at runtime
{
	freeThreadedMemoryOnNextUpdate = false;
#ifdef _DEBUG
	// Wait longer to disconnect in debug so I don't get disconnected while tracing
	timeoutTime=30000;
#else
	timeoutTime=10000;
#endif

#ifndef _RELEASE
	maxSendBPS=minExtraPing=extraPingVariance=0;
#endif

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

//-------------------------------------------------------------------------------------------------------
// Resets the layer for reuse
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101c1170
void ReliabilityLayer::Reset( bool resetVariables )
{
	FreeMemory( true ); // true because making a memory reset pending in the update cycle causes resets after reconnects.  Instead, just call Reset from a single thread
	if (resetVariables)
		InitializeVariables();
}

//-------------------------------------------------------------------------------------------------------
// Sets up encryption
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bbe10
void ReliabilityLayer::SetEncryptionKey( const unsigned char* key )
{
	if ( key )
		encryptor.SetKey( key );
	else
		encryptor.UnsetKey();
}

//-------------------------------------------------------------------------------------------------------
// Set the time, in MS, to use before considering ourselves disconnected after not being able to deliver a reliable packet
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bbe30
void ReliabilityLayer::SetTimeoutTime( RakNetTime time )
{
	timeoutTime=time;
}

//-------------------------------------------------------------------------------------------------------
// Returns the value passed to SetTimeoutTime. or the default if it was never called
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bbe40
RakNetTime ReliabilityLayer::GetTimeoutTime(void)
{
	return timeoutTime;
}

//-------------------------------------------------------------------------------------------------------
// Initialize the variables
//-------------------------------------------------------------------------------------------------------
static const RakNetTimeNS STARTING_TIME_BETWEEN_PACKETS=100000;

// FUNCTION: WEBSERVICE 0x101bbe50
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

//-------------------------------------------------------------------------------------------------------
// Frees all allocated memory
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::FreeMemory( bool freeAllImmediately )
{
	if ( freeAllImmediately )
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

void ReliabilityLayer::FreeThreadedMemory( void )
{
}

// FUNCTION: WEBSERVICE 0x101bfc50
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

#ifndef _RELEASE
	for (unsigned i = 0; i < delayList.Size(); i++ )
		delete delayList[ i ];
	delayList.Clear();
#endif

	internalPacketPool.Clear();

	//messageHistogram.Clear();

	acknowlegements.Clear();
}

//-------------------------------------------------------------------------------------------------------
// Packets are read directly from the socket layer and skip the reliability
//layer  because unconnected players do not use the reliability layer
// This function takes packet data after a player has been confirmed as
//connected.  The game should not use that data directly
// because some data is used internally, such as packet acknowledgement and
//split packets
//-------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma warning( disable : 4100 ) // warning C4100 : unreferenced formal parameter
#endif
// FUNCTION: WEBSERVICE 0x101c0140
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
		RakNetTime remoteTime;
		socketData.Read(remoteTime);
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

		ackPing = time - (RakNetTimeNS)remoteTime * (RakNetTimeNS)1000;

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

//-------------------------------------------------------------------------------------------------------
// This gets an end-user packet already parsed out. Returns number of BITS put into the buffer
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bd970
int ReliabilityLayer::Receive( unsigned char **data )
{
	// Wait until the clear occurs
	if (freeThreadedMemoryOnNextUpdate)
		return 0;

	InternalPacket * internalPacket;

	if ( outputQueue.Size() > 0 )
	{
		//  #ifdef _DEBUG
		//  assert(bitStream->GetNumberOfBitsUsed()==0);
		//  #endif
		internalPacket = outputQueue.Pop();

		int bitLength;
		*data = internalPacket->data;
		bitLength = internalPacket->dataBitLength;
		internalPacketPool.Release( internalPacket );
		return bitLength;
	}

	else
	{
		return 0;
	}

}

//-------------------------------------------------------------------------------------------------------
// Puts data on the send queue
// bitStream contains the data to send
// priority is what priority to send the data at
// reliability is what reliability to use
// ordering channel is from 0 to 255 and specifies what stream to use
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101be5a0
bool ReliabilityLayer::Send( char *data, int numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, unsigned char orderingChannel, bool makeDataCopy, int MTUSize, RakNetTimeNS currentTime )
{
#ifdef _DEBUG
	assert( !( reliability > RELIABLE_SEQUENCED || reliability < 0 ) );
	assert( !( priority > NUMBER_OF_PRIORITIES || priority < 0 ) );
	assert( !( orderingChannel < 0 || orderingChannel >= NUMBER_OF_ORDERED_STREAMS ) );
	assert( numberOfBitsToSend > 0 );
#endif

	// Fix any bad parameters
	if ( reliability > RELIABLE_SEQUENCED || reliability < 0 )
		reliability = RELIABLE;

	if ( priority > NUMBER_OF_PRIORITIES || priority < 0 )
		priority = HIGH_PRIORITY;

	if ( orderingChannel >= NUMBER_OF_ORDERED_STREAMS )
		orderingChannel = 0;

	int numberOfBytesToSend=BITS_TO_BYTES(numberOfBitsToSend);
	if ( numberOfBitsToSend == 0 )
	{
#ifdef _DEBUG
		printf( "Error!! ReliabilityLayer::Send bitStream->GetNumberOfBytesUsed()==0\n" );
#endif

		return false;
	}
	InternalPacket * internalPacket = internalPacketPool.Allocate();
	//InternalPacket * internalPacket = sendPacketSet[priority].WriteLock();
#ifdef _DEBUG
	// Remove accessing undefined memory warning
	memset( internalPacket, 255, sizeof( InternalPacket ) );
#endif

	internalPacket->creationTime = currentTime;

	if ( makeDataCopy )
	{
		internalPacket->data = new unsigned char [ numberOfBytesToSend ];
		memcpy( internalPacket->data, data, numberOfBytesToSend );
//		printf("Allocated %i\n", internalPacket->data);
	}
	else
	{
		// Allocated the data elsewhere, delete it in here
		internalPacket->data = ( unsigned char* ) data;
//		printf("Using Pre-Allocated %i\n", internalPacket->data);
	}

	internalPacket->dataBitLength = numberOfBitsToSend;
	internalPacket->nextActionTime = 0;

	internalPacket->messageNumber = (MessageNumberType) -1;
	internalPacket->messageNumberAssigned = false;

	internalPacket->priority = priority;
	internalPacket->reliability = reliability;
	internalPacket->splitPacketCount = 0;

	// Calculate if I need to split the packet
	int headerLength = BITS_TO_BYTES( GetBitStreamHeaderLength( internalPacket ) );

	int maxDataSize = MTUSize - UDP_HEADER_SIZE - headerLength;

	if ( encryptor.IsKeySet() )
		maxDataSize -= 16; // Extra data for the encryptor

	bool splitPacket = numberOfBytesToSend > maxDataSize;

	// If a split packet, we might have to upgrade the reliability
	if ( splitPacket )
		statistics.numberOfSplitMessages++;
	else
		statistics.numberOfUnsplitMessages++;


	if ( internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == UNRELIABLE_SEQUENCED )
	{
		// Assign the sequence stream and index
		internalPacket->orderingChannel = orderingChannel;
		internalPacket->orderingIndex = waitingForSequencedPacketWriteIndex[ orderingChannel ] ++;

		// This packet supersedes all other sequenced packets on the same ordering channel
		// Delete all packets in all send lists that are sequenced and on the same ordering channel
		// UPDATE:
		// Disabled.  We don't have enough info to consistently do this.  Sometimes newer data does supercede
		// older data such as with constantly declining health, but not in all cases.
		// For example, with sequenced unreliable sound packets just because you send a newer one doesn't mean you
		// don't need the older ones because the odds are they will still arrive in order
		/*
		  for (int i=0; i < NUMBER_OF_PRIORITIES; i++)
		  {
		  DeleteSequencedPacketsInList(orderingChannel, sendQueue[i]);
		  }
		*/
	}

	else
		if ( internalPacket->reliability == RELIABLE_ORDERED )
		{
			// Assign the ordering channel and index
			internalPacket->orderingChannel = orderingChannel;
			internalPacket->orderingIndex = waitingForOrderedPacketWriteIndex[ orderingChannel ] ++;
		}

	if ( splitPacket )   // If it uses a secure header it will be generated here
	{
		// Must split the packet.  This will also generate the SHA1 if it is required. It also adds it to the send list.
		//InternalPacket packetCopy;
		//memcpy(&packetCopy, internalPacket, sizeof(InternalPacket));
		//sendPacketSet[priority].CancelWriteLock(internalPacket);
		//SplitPacket( &packetCopy, MTUSize );
		SplitPacket( internalPacket, MTUSize );
		//delete [] packetCopy.data;
		return true;
	}

	sendPacketSet[ internalPacket->priority ].Push( internalPacket );

//	sendPacketSet[priority].WriteUnlock();
	return true;
}

//-------------------------------------------------------------------------------------------------------
// Run this once per game cycle.  Handles internal lists and actually does the send
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101c0b10
void ReliabilityLayer::Update( SOCKET s, SystemAddress systemAddress, int MTUSize, RakNetTimeNS time, unsigned maxBitsPerSecond, DataStructures::List<PluginInterface*> &messageHandlerList )
{
	// This line is necessary because the timer isn't accurate
	if (time <= lastUpdateTime)
	{
		// Always set the last time in case of overflow
		lastUpdateTime=time;
		return;
	}

	RakNetTimeNS elapsedTime = time - lastUpdateTime;
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
	if (maxBitsPerSecond && throughputCapCountdown > 0)
	{
		throughputCapCountdown -= elapsedTime;
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
		RakNetTimeNS timeSpent = 0;
		RakNetTimeNS timeSinceLastSend = time - nextSendTime;
		if (timeSinceLastSend > timeBetweenPackets*100)
		{
			timeSinceLastSend = timeBetweenPackets*100;
			nextSendTime = time;
		}
		while (timeSpent < timeSinceLastSend)
		{
			updateBitStream.Reset();
			if ( GenerateDatagram( &updateBitStream, MTUSize, &reliableDataSent, time, systemAddress, messageHandlerList )==false )
				break;

#ifndef _RELEASE
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
#endif
			SendBitStream( s, systemAddress, &updateBitStream );

			if (maxBitsPerSecond > 0)
			{
				throughputCapCountdown += (RakNetTimeNS)((double)updateBitStream.GetNumberOfBitsUsed() * 1000000.0 / (double)maxBitsPerSecond);
				if (throughputCapCountdown > 30000)
					break;
			}

			timeSpent += timeBetweenPackets;
		}

		nextSendTime += timeSpent;

		// The send loop ran to completion, so there is more waiting than the window allows.
		if (timeSpent >= timeSinceLastSend)
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

		if (maxBitsPerSecond > 0)
			throughputCapCountdown += (RakNetTimeNS)((double)updateBitStream.GetNumberOfBitsUsed() * 1000000.0 / (double)maxBitsPerSecond);
	}

DO_LAGGED_SENDS:
	;
#ifndef _RELEASE
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
			delayList.Del();
		}

		else
			i++;
	}
#endif

}

//-------------------------------------------------------------------------------------------------------
// Writes a bitstream to the socket
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bbfb0
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

//-------------------------------------------------------------------------------------------------------
// Generates a datagram (coalesced packets)
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bee70
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
	bool hasAcks;
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
		hasAcks=true;
		statistics.acknowlegementBitsSent +=acknowlegements.Serialize(output, (MTUSize-UDP_HEADER_SIZE)*8-1, true);
	}
	else
	{
		hasAcks=false;
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

	if (hasAcks || wroteData)
		sendPacketCount++;

	return hasAcks || wroteData;
}

//-------------------------------------------------------------------------------------------------------
// Are we waiting for any data to be sent out or be processed by the player?
//-------------------------------------------------------------------------------------------------------
bool ReliabilityLayer::IsDataWaiting(void)
{
	unsigned i;
	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		if (sendPacketSet[ i ].Size() > 0)
			return true;
	}

	return acknowlegements.Size() > 0 || resendList.IsEmpty()==false || outputQueue.Size() > 0 || orderingList.Size() > 0 || splitPacketChannelList.Size() > 0;
}

// FUNCTION: WEBSERVICE 0x101bda40
bool ReliabilityLayer::AreAcksWaiting(void)
{
	return acknowlegements.Size() > 0;
}

//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bc050
void ReliabilityLayer::ApplyNetworkSimulator( double _maxSendBPS, RakNetTime _minExtraPing, RakNetTime _extraPingVariance )
{
#ifndef _RELEASE
	maxSendBPS=_maxSendBPS;
	minExtraPing=_minExtraPing;
	extraPingVariance=_extraPingVariance;
#endif
}
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bc080
void ReliabilityLayer::SetSplitMessageProgressInterval(int interval)
{
	splitMessageProgressInterval=interval;
}
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bc090
void ReliabilityLayer::SetUnreliableTimeout(RakNetTime timeoutMS)
{
	unreliableTimeout=(RakNetTimeNS)timeoutMS*(RakNetTimeNS)1000;
}

//-------------------------------------------------------------------------------------------------------
// This will return true if we should not send at this time
//-------------------------------------------------------------------------------------------------------
bool ReliabilityLayer::IsSendThrottled( int MTUSize )
{
	return false;
//	return resendList.Size() > windowSize;

	// Disabling this, because it can get stuck here forever
	/*
	unsigned packetsWaiting;
	unsigned resendListDataSize=0;
	unsigned i;
	for (i=0; i < resendList.Size(); i++)
	{
		if (resendList[i])
			resendListDataSize+=resendList[i]->dataBitLength;
	}
	packetsWaiting = 1 + ((BITS_TO_BYTES(resendListDataSize)) / (MTUSize - UDP_HEADER_SIZE - 10)); // 10 to roughly estimate the raknet header

	return packetsWaiting >= windowSize;
	*/
}

//-------------------------------------------------------------------------------------------------------
// We lost a packet
//-------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma warning( disable : 4100 ) // warning C4100 : unreferenced formal parameter
#endif
void ReliabilityLayer::UpdateWindowFromPacketloss( RakNetTimeNS time )
{

}

//-------------------------------------------------------------------------------------------------------
// Increase the window size
//-------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma warning( disable : 4100 ) // warning C4100 : unreferenced formal parameter
#endif
void ReliabilityLayer::UpdateWindowFromAck( RakNetTimeNS time )
{

}

//-------------------------------------------------------------------------------------------------------
// Acknowledge receipt of the packet with the specified messageNumber
//-------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma warning( disable : 4100 ) // warning C4100 : unreferenced formal parameter
#endif
void ReliabilityLayer::SendAcknowledgementPacket( const MessageNumberType messageNumber, RakNetTimeNS time )
{
	statistics.acknowlegementsSent++;
 	acknowlegements.Insert(messageNumber);
}

//-------------------------------------------------------------------------------------------------------
// Parse an internalPacket and figure out how many header bits would be
// written.  Returns that number
//-------------------------------------------------------------------------------------------------------
int ReliabilityLayer::GetBitStreamHeaderLength( const InternalPacket *const internalPacket )
{
#ifdef _DEBUG
	assert( internalPacket );
#endif

	int bitLength;

	bitLength=sizeof(MessageNumberType)*8;

	// Write the PacketReliability.  This is encoded in 3 bits
	//bitStream->WriteBits((unsigned char*)&(internalPacket->reliability), 3, true);
	bitLength += 3;

	// If the reliability requires an ordering channel and ordering index, we Write those.
	if ( internalPacket->reliability == UNRELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_ORDERED )
	{
		// ordering channel encoded in 5 bits (from 0 to 31)
		//bitStream->WriteBits((unsigned char*)&(internalPacket->orderingChannel), 5, true);
		bitLength+=5;

		// ordering index is one byte
		//bitStream->WriteCompressed(internalPacket->orderingIndex);
		bitLength+=sizeof(OrderingIndexType)*8;
	}

	// Write if this is a split packet (1 bit)
	bool isSplitPacket = internalPacket->splitPacketCount > 0;

	//bitStream->Write(isSplitPacket);
	bitLength += 1;

	if ( isSplitPacket )
	{
		// split packet indices are two bytes (so one packet can be split up to 65535
		// times - maximum packet size would be about 500 * 65535)
		//bitStream->Write(internalPacket->splitPacketId);
		//bitStream->WriteCompressed(internalPacket->splitPacketIndex);
		//bitStream->WriteCompressed(internalPacket->splitPacketCount);
		bitLength += (sizeof(SplitPacketIdType) + sizeof(SplitPacketIndexType) * 2) * 8;
	}

	// Write how many bits the packet data is. Stored in an unsigned short and
	// read from 16 bits
	//bitStream->WriteBits((unsigned char*)&(internalPacket->dataBitLength), 16, true);

	// Read how many bits the packet data is.  Stored in 16 bits
	bitLength += 16;

	// Byte alignment
	//bitLength += 8 - ((bitLength -1) %8 + 1);

	return bitLength;
}

//-------------------------------------------------------------------------------------------------------
// Parse an internalPacket and create a bitstream to represent this data
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bcc00
int ReliabilityLayer::WriteToBitStreamFromInternalPacket( RakNet::BitStream *bitStream, const InternalPacket *const internalPacket, RakNetTimeNS curTime )
{
#ifdef _DEBUG
	assert( bitStream && internalPacket );
#endif

	int start = bitStream->GetNumberOfBitsUsed();
	const unsigned char c = (unsigned char) internalPacket->reliability;

	// testing
	//if (internalPacket->reliability==UNRELIABLE)
	//  printf("Sending unreliable packet %i\n", internalPacket->messageNumber);
	//else if (internalPacket->reliability==RELIABLE_SEQUENCED || internalPacket->reliability==RELIABLE_ORDERED || internalPacket->reliability==RELIABLE)
	//	  printf("Sending reliable packet number %i\n", internalPacket->messageNumber);

	//bitStream->AlignWriteToByteBoundary();

	// Write the message number (2 bytes)
	bitStream->Write( internalPacket->messageNumber );

	// Acknowledgment packets have no more data than the messageNumber and whether it is anacknowledgment


#ifdef _DEBUG
	assert( internalPacket->dataBitLength > 0 );
#endif

	// Write the PacketReliability.  This is encoded in 3 bits
	bitStream->WriteBits( (const unsigned char *)&c, 3, true );

	// If the reliability requires an ordering channel and ordering index, we Write those.
	if ( internalPacket->reliability == UNRELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_ORDERED )
	{
		// ordering channel encoded in 5 bits (from 0 to 31)
		bitStream->WriteBits( ( unsigned char* ) & ( internalPacket->orderingChannel ), 5, true );

		// One or two bytes
		bitStream->Write( internalPacket->orderingIndex );
	}

	// Write if this is a split packet (1 bit)
	bool isSplitPacket = internalPacket->splitPacketCount > 0;

	bitStream->Write( isSplitPacket );

	if ( isSplitPacket )
	{
		bitStream->Write( internalPacket->splitPacketId );
		bitStream->WriteCompressed( internalPacket->splitPacketIndex );
		bitStream->WriteCompressed( internalPacket->splitPacketCount );
	}

	// Write how many bits the packet data is. Stored in 13 bits
#ifdef _DEBUG
	assert( BITS_TO_BYTES( internalPacket->dataBitLength ) < MAXIMUM_MTU_SIZE ); // I never send more than MTU_SIZE bytes

#endif

	unsigned short length = ( unsigned short ) internalPacket->dataBitLength; // Ignore the 2 high bytes for WriteBits

	bitStream->WriteCompressed( length );

	// Write the actual data.
	bitStream->WriteAlignedBytes( ( unsigned char* ) internalPacket->data, BITS_TO_BYTES( internalPacket->dataBitLength ) );

	//bitStream->WriteBits((unsigned char*)internalPacket->data, internalPacket->dataBitLength);

	return bitStream->GetNumberOfBitsUsed() - start;
}

//-------------------------------------------------------------------------------------------------------
// Parse a bitstream and create an internal packet to represent this data
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bda50
InternalPacket* ReliabilityLayer::CreateInternalPacketFromBitStream( RakNet::BitStream *bitStream, RakNetTimeNS time )
{
	bool bitStreamSucceeded;
	InternalPacket* internalPacket;

	if ( bitStream->GetNumberOfUnreadBits() < (int) sizeof( internalPacket->messageNumber ) * 8 )
		return 0; // leftover bits

	internalPacket = internalPacketPool.Allocate();

#ifdef _DEBUG
	// Remove accessing undefined memory error
	memset( internalPacket, 255, sizeof( InternalPacket ) );
#endif

	internalPacket->creationTime = time;

	//bitStream->AlignReadToByteBoundary();

	// Read the packet number (2 bytes)
	bitStreamSucceeded = bitStream->Read( internalPacket->messageNumber );

#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets
	//assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		internalPacketPool.Release( internalPacket );
		return 0;
	}

#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets
	//assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		internalPacketPool.Release( internalPacket );
		return 0;
	}

	// Read the PacketReliability. This is encoded in 3 bits
	unsigned char reliability;

	bitStreamSucceeded = bitStream->ReadBits( ( unsigned char* ) ( &( reliability ) ), 3 );

	internalPacket->reliability = ( const PacketReliability ) reliability;

#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets
	// assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		internalPacketPool.Release( internalPacket );
		return 0;
	}

	// If the reliability requires an ordering channel and ordering index, we read those.
	if ( internalPacket->reliability == UNRELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_SEQUENCED || internalPacket->reliability == RELIABLE_ORDERED )
	{
		// ordering channel encoded in 5 bits (from 0 to 31)
		bitStreamSucceeded = bitStream->ReadBits( ( unsigned char* ) & ( internalPacket->orderingChannel ), 5 );
#ifdef _DEBUG
		// 10/08/05 - Disabled assert since this hits from offline packets
		//assert( bitStreamSucceeded );
#endif

		if ( bitStreamSucceeded == false )
		{
			internalPacketPool.Release( internalPacket );
			return 0;
		}

		bitStreamSucceeded = bitStream->Read( internalPacket->orderingIndex );

#ifdef _DEBUG
		// 10/08/05 - Disabled assert since this hits from offline packets
		//assert( bitStreamSucceeded );
#endif

		if ( bitStreamSucceeded == false )
		{
			internalPacketPool.Release( internalPacket );
			return 0;
		}
	}

	// Read if this is a split packet (1 bit)
	bool isSplitPacket;

	bitStreamSucceeded = bitStream->Read( isSplitPacket );

#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets
	//assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		internalPacketPool.Release( internalPacket );
		return 0;
	}

	if ( isSplitPacket )
	{
		bitStreamSucceeded = bitStream->Read( internalPacket->splitPacketId );
#ifdef _DEBUG
		// 10/08/05 - Disabled assert since this hits from offline packets
		// assert( bitStreamSucceeded );
#endif

		if ( bitStreamSucceeded == false )
		{
			internalPacketPool.Release( internalPacket );
			return 0;
		}

		bitStreamSucceeded = bitStream->ReadCompressed( internalPacket->splitPacketIndex );
#ifdef _DEBUG
		// 10/08/05 - Disabled assert since this hits from offline packets
		//assert( bitStreamSucceeded );
#endif

		if ( bitStreamSucceeded == false )
		{
			internalPacketPool.Release( internalPacket );
			return 0;
		}

		bitStreamSucceeded = bitStream->ReadCompressed( internalPacket->splitPacketCount );
#ifdef _DEBUG
		// 10/08/05 - Disabled assert since this hits from offline packets
		//assert( bitStreamSucceeded );
#endif

		if ( bitStreamSucceeded == false )
		{
			internalPacketPool.Release( internalPacket );
			return 0;
		}
	}

	else
		internalPacket->splitPacketIndex = internalPacket->splitPacketCount = 0;

	// Optimization - do byte alignment here
	//unsigned char zero;
	//bitStream->ReadBits(&zero, 8 - (bitStream->GetNumberOfBitsUsed() %8));
	//assert(zero==0);


	unsigned short length;

	bitStreamSucceeded = bitStream->ReadCompressed( length );

	// Read into an unsigned short.  Otherwise the data would be offset too high by two bytes
#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets
	//assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		internalPacketPool.Release( internalPacket );
		return 0;
	}

	internalPacket->dataBitLength = length;
#ifdef _DEBUG
	// 10/08/05 - Disabled assert since this hits from offline packets arriving when the sender does not know we just connected, which is an unavoidable condition sometimes
	//	assert( internalPacket->dataBitLength > 0 && BITS_TO_BYTES( internalPacket->dataBitLength ) < MAXIMUM_MTU_SIZE );
#endif
	if ( ! ( internalPacket->dataBitLength > 0 && BITS_TO_BYTES( internalPacket->dataBitLength ) < MAXIMUM_MTU_SIZE ) )
	{
		// 10/08/05 - internalPacket->data wasn't allocated yet
		//	delete [] internalPacket->data;
		internalPacketPool.Release( internalPacket );
		return 0;
	}

	// Allocate memory to hold our data
	internalPacket->data = new unsigned char [ BITS_TO_BYTES( internalPacket->dataBitLength ) ];
	//printf("Allocating %i\n",  internalPacket->data);

	// Set the last byte to 0 so if ReadBits does not read a multiple of 8 the last bits are 0'ed out
	internalPacket->data[ BITS_TO_BYTES( internalPacket->dataBitLength ) - 1 ] = 0;

	// Read the data the packet holds
	bitStreamSucceeded = bitStream->ReadAlignedBytes( ( unsigned char* ) internalPacket->data, BITS_TO_BYTES( internalPacket->dataBitLength ) );

	//bitStreamSucceeded = bitStream->ReadBits((unsigned char*)internalPacket->data, internalPacket->dataBitLength);
#ifdef _DEBUG

	// 10/08/05 - Disabled assert since this hits from offline packets
	//assert( bitStreamSucceeded );
#endif

	if ( bitStreamSucceeded == false )
	{
		delete [] internalPacket->data;
		internalPacketPool.Release( internalPacket );
		return 0;
	}


	// PRINTING UNRELIABLE STRINGS
	// if (internalPacket->data && internalPacket->dataBitLength>5*8)
	//  printf("Received %s\n",internalPacket->data);

	return internalPacket;
}

//-------------------------------------------------------------------------------------------------------
// Get the SHA1 code
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::GetSHA1( unsigned char * const buffer, unsigned int
				nbytes, char code[ SHA1_LENGTH ] )
{
	CSHA1 sha1;

	sha1.Reset();
	sha1.Update( ( unsigned char* ) buffer, nbytes );
	sha1.Final();
	memcpy( code, sha1.GetHash(), SHA1_LENGTH );
}

//-------------------------------------------------------------------------------------------------------
// Check the SHA1 code
//-------------------------------------------------------------------------------------------------------
bool ReliabilityLayer::CheckSHA1( char code[ SHA1_LENGTH ], unsigned char *
				  const buffer, unsigned int nbytes )
{
	char code2[ SHA1_LENGTH ];
	GetSHA1( buffer, nbytes, code2 );

	for ( int i = 0; i < SHA1_LENGTH; i++ )
		if ( code[ i ] != code2[ i ] )
			return false;

	return true;
}

//-------------------------------------------------------------------------------------------------------
// Search the specified list for sequenced packets on the specified ordering
// stream, optionally skipping those with splitPacketId, and delete them
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::List<InternalPacket*>&theList, int splitPacketId )
{
	unsigned i = 0;

	while ( i < theList.Size() )
	{
		if ( ( theList[ i ]->reliability == RELIABLE_SEQUENCED || theList[ i ]->reliability == UNRELIABLE_SEQUENCED ) &&
			theList[ i ]->orderingChannel == orderingChannel && ( splitPacketId == -1 || theList[ i ]->splitPacketId != (unsigned int) splitPacketId ) )
		{
			InternalPacket * internalPacket = theList[ i ];
			theList.RemoveAtIndex( i );
			delete [] internalPacket->data;
			internalPacketPool.Release( internalPacket );
		}

		else
			i++;
	}
}

//-------------------------------------------------------------------------------------------------------
// Search the specified list for sequenced packets with a value less than orderingIndex and delete them
// Note - I added functionality so you can use the Queue as a list (in this case for searching) but it is less efficient to do so than a regular list
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::DeleteSequencedPacketsInList( unsigned char orderingChannel, DataStructures::Queue<InternalPacket*>&theList )
{
	InternalPacket * internalPacket;
	int listSize = theList.Size();
	int i = 0;

	while ( i < listSize )
	{
		if ( ( theList[ i ]->reliability == RELIABLE_SEQUENCED || theList[ i ]->reliability == UNRELIABLE_SEQUENCED ) && theList[ i ]->orderingChannel == orderingChannel )
		{
			internalPacket = theList[ i ];
			theList.RemoveAtIndex( i );
			delete [] internalPacket->data;
			internalPacketPool.Release( internalPacket );
			listSize--;
		}

		else
			i++;
	}
}

//-------------------------------------------------------------------------------------------------------
// Returns true if newPacketOrderingIndex is older than the waitingForPacketOrderingIndex
//-------------------------------------------------------------------------------------------------------
bool ReliabilityLayer::IsOlderOrderedPacket( OrderingIndexType newPacketOrderingIndex, OrderingIndexType waitingForPacketOrderingIndex )
{
	// This should give me 255 or 65535
	OrderingIndexType maxRange = (OrderingIndexType) -1;

	if ( waitingForPacketOrderingIndex > maxRange/2 )
	{
		if ( newPacketOrderingIndex >= waitingForPacketOrderingIndex - maxRange/2+1 && newPacketOrderingIndex < waitingForPacketOrderingIndex )
		{
			return true;
		}
	}

	else
		if ( newPacketOrderingIndex >= ( OrderingIndexType ) ( waitingForPacketOrderingIndex - (( OrderingIndexType ) maxRange/2+1) ) ||
			newPacketOrderingIndex < waitingForPacketOrderingIndex )
		{
			return true;
		}

	// Old packet
	return false;
}

//-------------------------------------------------------------------------------------------------------
// Split the passed packet into chunks under MTU_SIZEbytes (including headers) and save those new chunks
// Optimized version
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bdbf0
void ReliabilityLayer::SplitPacket( InternalPacket *internalPacket, int MTUSize )
{
	// Doing all sizes in bytes in this function so I don't write partial bytes with split packets
	internalPacket->splitPacketCount = 1; // This causes GetBitStreamHeaderLength to account for the split packet header
	int headerLength = BITS_TO_BYTES( GetBitStreamHeaderLength( internalPacket ) );
	int dataByteLength = BITS_TO_BYTES( internalPacket->dataBitLength );
	int maxDataSize;
	int maximumSendBlock, byteOffset, bytesToSend;
	SplitPacketIndexType splitPacketIndex;
	int i;
	InternalPacket **internalPacketArray;

	maxDataSize = MTUSize - UDP_HEADER_SIZE;

	if ( encryptor.IsKeySet() )
		maxDataSize -= 16; // Extra data for the encryptor

#ifdef _DEBUG
	// Make sure we need to split the packet to begin with
	assert( dataByteLength > maxDataSize - headerLength );
#endif

	// How much to send in the largest block
	maximumSendBlock = maxDataSize - headerLength;

	// Calculate how many packets we need to create
	internalPacket->splitPacketCount = ( ( dataByteLength - 1 ) / ( maximumSendBlock ) + 1 );

	statistics.totalSplits += internalPacket->splitPacketCount;

	// Optimization
	// internalPacketArray = new InternalPacket*[internalPacket->splitPacketCount];
	bool usedAlloca=false;
	#if !defined(_COMPATIBILITY_1)
	if (sizeof( InternalPacket* ) * internalPacket->splitPacketCount < MAX_ALLOCA_STACK_ALLOCATION)
	{
		internalPacketArray = ( InternalPacket** ) alloca( sizeof( InternalPacket* ) * internalPacket->splitPacketCount );
		usedAlloca=true;
	}
	else
	#endif
		internalPacketArray = new InternalPacket*[internalPacket->splitPacketCount];

	for ( i = 0; i < ( int ) internalPacket->splitPacketCount; i++ )
	{
		internalPacketArray[ i ] = internalPacketPool.Allocate();
		//internalPacketArray[ i ] = (InternalPacket*) alloca( sizeof( InternalPacket ) );
//		internalPacketArray[ i ] = sendPacketSet[internalPacket->priority].WriteLock();
		memcpy( internalPacketArray[ i ], internalPacket, sizeof( InternalPacket ) );
	}

	// This identifies which packet this is in the set
	splitPacketIndex = 0;

	// Do a loop to send out all the packets
	do
	{
		byteOffset = splitPacketIndex * maximumSendBlock;
		bytesToSend = dataByteLength - byteOffset;

		if ( bytesToSend > maximumSendBlock )
			bytesToSend = maximumSendBlock;

		// Copy over our chunk of data
		internalPacketArray[ splitPacketIndex ]->data = new unsigned char[ bytesToSend ];

		memcpy( internalPacketArray[ splitPacketIndex ]->data, internalPacket->data + byteOffset, bytesToSend );

		if ( bytesToSend != maximumSendBlock )
			internalPacketArray[ splitPacketIndex ]->dataBitLength = internalPacket->dataBitLength - splitPacketIndex * ( maximumSendBlock << 3 );
		else
			internalPacketArray[ splitPacketIndex ]->dataBitLength = bytesToSend << 3;

		internalPacketArray[ splitPacketIndex ]->splitPacketIndex = splitPacketIndex;
		internalPacketArray[ splitPacketIndex ]->splitPacketId = splitPacketId;
		internalPacketArray[ splitPacketIndex ]->splitPacketCount = internalPacket->splitPacketCount;

		if ( splitPacketIndex > 0 )   // For the first split packet index we keep the messageNumber already assigned
		{
			// For every further packet we use a new messageNumber.
			// Note that all split packets are reliable
			internalPacketArray[ splitPacketIndex ]->messageNumber = (MessageNumberType) -1;
			internalPacketArray[ splitPacketIndex ]->messageNumberAssigned = false;

		}

		// Add the new packet to send list at the correct priority
		//  sendQueue[internalPacket->priority].Insert(newInternalPacket);
		// SHOW SPLIT PACKET GENERATION
		// if (splitPacketIndex % 100 == 0)
		//  printf("splitPacketIndex=%i\n",splitPacketIndex);
		//} while(++splitPacketIndex < internalPacket->splitPacketCount);
	}

	while ( ++splitPacketIndex < internalPacket->splitPacketCount );

	splitPacketId++; // It's ok if this wraps to 0

//	InternalPacket *workingPacket;

	// Copy all the new packets into the split packet list
	for ( i = 0; i < ( int ) internalPacket->splitPacketCount; i++ )
	{
		sendPacketSet[ internalPacket->priority ].Push( internalPacketArray[ i ] );
//		workingPacket=sendPacketSet[internalPacket->priority].WriteLock();
//		memcpy(workingPacket, internalPacketArray[ i ], sizeof(InternalPacket));
//		sendPacketSet[internalPacket->priority].WriteUnlock();
	}

	// Delete the original
	delete [] internalPacket->data;
	internalPacketPool.Release( internalPacket );

	if (usedAlloca==false)
		delete [] internalPacketArray;
}

//-------------------------------------------------------------------------------------------------------
// Insert a packet into the split packet list
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bf4c0
void ReliabilityLayer::InsertIntoSplitPacketList( InternalPacket * internalPacket, RakNetTimeNS time )
{
	bool objectExists;
	unsigned index;
	index=splitPacketChannelList.GetIndexFromKey(internalPacket->splitPacketId, &objectExists);
	if (objectExists==false)
	{
		SplitPacketChannel *newChannel = new SplitPacketChannel;
        index=splitPacketChannelList.Insert(internalPacket->splitPacketId, newChannel, true);
	}
	splitPacketChannelList[index]->splitPacketList.Insert(internalPacket->splitPacketIndex, internalPacket, true);
	splitPacketChannelList[index]->lastUpdateTime=time;

	if (splitMessageProgressInterval &&
		splitPacketChannelList[index]->splitPacketList[0]->splitPacketIndex==0 &&
		splitPacketChannelList[index]->splitPacketList.Size()!=splitPacketChannelList[index]->splitPacketList[0]->splitPacketCount &&
		(splitPacketChannelList[index]->splitPacketList.Size()%splitMessageProgressInterval)==0)
	{
//		printf("msgID=%i Progress %i/%i Partsize=%i\n",
//			splitPacketChannelList[index]->splitPacketList[0]->data[0],
//			splitPacketChannelList[index]->splitPacketList.Size(),
//			internalPacket->splitPacketCount,
//			BITS_TO_BYTES(splitPacketChannelList[index]->splitPacketList[0]->dataBitLength));

		// Return ID_DOWNLOAD_PROGRESS
		// Write splitPacketIndex (SplitPacketIndexType)
		// Write splitPacketCount (SplitPacketIndexType)
		// Write byteLength (4)
		// Write data, splitPacketChannelList[index]->splitPacketList[0]->data
		InternalPacket *progressIndicator = internalPacketPool.Allocate();
		unsigned int length = sizeof(MessageID) + sizeof(unsigned int)*2 + sizeof(unsigned int) + BITS_TO_BYTES(splitPacketChannelList[index]->splitPacketList[0]->dataBitLength);
		progressIndicator->data = new unsigned char [length];
		progressIndicator->dataBitLength=BYTES_TO_BITS(length);
		progressIndicator->data[0]=(MessageID)ID_DOWNLOAD_PROGRESS;
		unsigned int temp;
		temp=splitPacketChannelList[index]->splitPacketList.Size();
		memcpy(progressIndicator->data+sizeof(MessageID), &temp, sizeof(unsigned int));
		temp=(unsigned int)internalPacket->splitPacketCount;
		memcpy(progressIndicator->data+sizeof(MessageID)+sizeof(unsigned int)*1, &temp, sizeof(unsigned int));
		temp=BITS_TO_BYTES(splitPacketChannelList[index]->splitPacketList[0]->dataBitLength);
		memcpy(progressIndicator->data+sizeof(MessageID)+sizeof(unsigned int)*2, &temp, sizeof(unsigned int));
		memcpy(progressIndicator->data+sizeof(MessageID)+sizeof(unsigned int)*3, splitPacketChannelList[index]->splitPacketList[0]->data, BITS_TO_BYTES(splitPacketChannelList[index]->splitPacketList[0]->dataBitLength));
		outputQueue.Push(progressIndicator);
	}
}

//-------------------------------------------------------------------------------------------------------
// Take all split chunks with the specified splitPacketId and try to
//reconstruct a packet.  If we can, allocate and return it.  Otherwise return 0
// Optimized version
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bf6a0
InternalPacket * ReliabilityLayer::BuildPacketFromSplitPacketList( SplitPacketIdType splitPacketId, RakNetTimeNS time )
{
	unsigned i, j;
	unsigned byteProgress;
	InternalPacket * internalPacket;
	bool objectExists;

	i=splitPacketChannelList.GetIndexFromKey(splitPacketId, &objectExists);
#ifdef _DEBUG
	assert(objectExists);
#endif

	if (splitPacketChannelList[i]->splitPacketList.Size()==splitPacketChannelList[i]->splitPacketList[0]->splitPacketCount)
	{
		// Reconstruct
		internalPacket = CreateInternalPacketCopy( splitPacketChannelList[i]->splitPacketList[0], 0, 0, time );
		internalPacket->dataBitLength=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
			internalPacket->dataBitLength+=splitPacketChannelList[i]->splitPacketList[j]->dataBitLength;

		internalPacket->data = new unsigned char[ BITS_TO_BYTES( internalPacket->dataBitLength ) ];

		byteProgress=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			memcpy(internalPacket->data+byteProgress, splitPacketChannelList[i]->splitPacketList[j]->data, BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength));
			byteProgress+=BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength);
		}

		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			delete [] splitPacketChannelList[i]->splitPacketList[j]->data;
			internalPacketPool.Release(splitPacketChannelList[i]->splitPacketList[j]);
		}
		delete splitPacketChannelList[i];
		splitPacketChannelList.RemoveAtIndex(i);

		return internalPacket;
	}

	return 0;
}

// Delete any unreliable split packets that have long since expired
// FUNCTION: WEBSERVICE 0x101bf870
void ReliabilityLayer::DeleteOldUnreliableSplitPackets( RakNetTimeNS time )
{
	unsigned i,j;
	i=0;
	while (i < splitPacketChannelList.Size())
	{
		if (time > splitPacketChannelList[i]->lastUpdateTime + (RakNetTimeNS)timeoutTime*(RakNetTimeNS)1000 &&
			(splitPacketChannelList[i]->splitPacketList[0]->reliability==UNRELIABLE || splitPacketChannelList[i]->splitPacketList[0]->reliability==UNRELIABLE_SEQUENCED))
		{
			for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
			{
				delete [] splitPacketChannelList[i]->splitPacketList[j]->data;
				internalPacketPool.Release(splitPacketChannelList[i]->splitPacketList[j]);
			}
			delete splitPacketChannelList[i];
			splitPacketChannelList.RemoveAtIndex(i);
		}
		else
			i++;
	}
}

//-------------------------------------------------------------------------------------------------------
// Creates a copy of the specified internal packet with data copied from the original starting at dataByteOffset for dataByteLength bytes.
// Does not copy any split data parameters as that information is always generated does not have any reason to be copied
//-------------------------------------------------------------------------------------------------------
InternalPacket * ReliabilityLayer::CreateInternalPacketCopy( InternalPacket *original, int dataByteOffset, int dataByteLength, RakNetTimeNS time )
{
	InternalPacket * copy = internalPacketPool.Allocate();
#ifdef _DEBUG
	// Remove accessing undefined memory error
	memset( copy, 255, sizeof( InternalPacket ) );
#endif
	// Copy over our chunk of data

	if ( dataByteLength > 0 )
	{
		copy->data = new unsigned char[ dataByteLength ];
		memcpy( copy->data, original->data + dataByteOffset, dataByteLength );
	}
	else
		copy->data = 0;

	copy->dataBitLength = dataByteLength << 3;
	copy->creationTime = time;
	copy->nextActionTime = 0;
	copy->orderingIndex = original->orderingIndex;
	copy->orderingChannel = original->orderingChannel;
	copy->messageNumber = original->messageNumber;
	copy->priority = original->priority;
	copy->reliability = original->reliability;

	return copy;
}

//-------------------------------------------------------------------------------------------------------
// Get the specified ordering list
//-------------------------------------------------------------------------------------------------------
DataStructures::LinkedList<InternalPacket*> *ReliabilityLayer::GetOrderingListAtOrderingStream( unsigned char orderingChannel )
{
	if ( orderingChannel >= orderingList.Size() )
		return 0;

	return orderingList[ orderingChannel ];
}

//-------------------------------------------------------------------------------------------------------
// Add the internal packet to the ordering list in order based on order index
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101be740
void ReliabilityLayer::AddToOrderingList( InternalPacket * internalPacket )
{
#ifdef _DEBUG
	assert( internalPacket->orderingChannel < NUMBER_OF_ORDERED_STREAMS );
#endif

	if ( internalPacket->orderingChannel >= NUMBER_OF_ORDERED_STREAMS )
	{
		return;
	}

	DataStructures::LinkedList<InternalPacket*> *theList;

	if ( internalPacket->orderingChannel >= orderingList.Size() || orderingList[ internalPacket->orderingChannel ] == 0 )
	{
		// Need a linked list in this index
		orderingList.Replace( new DataStructures::LinkedList<InternalPacket*>, 0, internalPacket->orderingChannel );
		theList=orderingList[ internalPacket->orderingChannel ];
	}
	else
	{
		// Have a linked list in this index
		if ( orderingList[ internalPacket->orderingChannel ]->Size() == 0 )
		{
			theList=orderingList[ internalPacket->orderingChannel ];
		}
		else
		{
			theList = GetOrderingListAtOrderingStream( internalPacket->orderingChannel );
		}
	}

	theList->End();
	theList->Add(internalPacket);
}

//-------------------------------------------------------------------------------------------------------
// Inserts a packet into the resend list in order
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::InsertPacketIntoResendList( InternalPacket *internalPacket, RakNetTimeNS time, bool makeCopyOfInternalPacket, bool firstResend )
{
	// lastAckTime is the time we last got an acknowledgment - however we also initialize the value if this is the first resend and
	// either we never got an ack before or we are inserting into an empty resend queue
	if ( firstResend && (lastAckTime == 0 || resendList.IsEmpty()))
	{
		lastAckTime = time; // Start the timer for the ack of this packet if we aren't already waiting for an ack
	}

	if (makeCopyOfInternalPacket)
	{
		InternalPacket *pool=internalPacketPool.Allocate();
		//printf("Adding %i\n", internalPacket->data);
		memcpy(pool, internalPacket, sizeof(InternalPacket));
		resendQueue.Push( pool );
	}
	else
	{
		RakAssert(internalPacket->nextActionTime!=0);

		resendQueue.Push( internalPacket );
	}

}

//-------------------------------------------------------------------------------------------------------
// If Read returns -1 and this returns true then a modified packet was detected
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bc0b0
bool ReliabilityLayer::IsCheater( void ) const
{
	return cheater;
}

//-------------------------------------------------------------------------------------------------------
//  Were you ever unable to deliver a packet despite retries?
//-------------------------------------------------------------------------------------------------------
// FUNCTION: WEBSERVICE 0x101bc0c0
bool ReliabilityLayer::IsDeadConnection( void ) const
{
	return deadConnection;
}

//-------------------------------------------------------------------------------------------------------
//  Causes IsDeadConnection to return true
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::KillConnection( void )
{
	deadConnection=true;
}

//-------------------------------------------------------------------------------------------------------
// Statistics
//-------------------------------------------------------------------------------------------------------
RakNetStatistics * const ReliabilityLayer::GetStatistics( void )
{
	unsigned i;

	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		statistics.messageSendBuffer[i] = sendPacketSet[i].Size();
	}

	statistics.acknowlegementsPending = acknowlegements.Size();
	if (lastUpdateTime > histogramStart && histogramBitsSent > 0)
		statistics.bitsPerSecond = (double) histogramBitsSent /
			((double)(lastUpdateTime - histogramStart) / 1000000.0);
	else
		statistics.bitsPerSecond = 0.0;
	statistics.messagesWaitingForReassembly = 0;
	for (i=0; i < splitPacketChannelList.Size(); i++)
		statistics.messagesWaitingForReassembly+=splitPacketChannelList[i]->splitPacketList.Size();
	statistics.internalOutputQueueSize = outputQueue.Size();
	statistics.isLimitedByCongestionControl = continuousSend && lastUpdateTime - lastTimeBetweenPacketsIncrease > 1000000;
	//statistics.lossySize = lossyWindowSize == MAXIMUM_WINDOW_SIZE + 1 ? 0 : lossyWindowSize;
//	statistics.lossySize=0;
	statistics.messagesOnResendQueue = GetResendListDataSize();

	return &statistics;
}

//-------------------------------------------------------------------------------------------------------
// Returns the number of packets in the resend queue, not counting holes
//-------------------------------------------------------------------------------------------------------
unsigned int ReliabilityLayer::GetResendListDataSize(void) const
{
	/*
	unsigned int i, count;
	for (count=0, i=0; i < resendList.Size(); i++)
		if (resendList[i]!=0)
			count++;
	return count;
	*/

	// Not accurate but thread-safe.  The commented version might crash if the queue is cleared while we loop through it
	return resendList.Size();
}

//-------------------------------------------------------------------------------------------------------
// Process threaded commands
//-------------------------------------------------------------------------------------------------------
void ReliabilityLayer::UpdateThreadedMemory(void)
{
	if ( freeThreadedMemoryOnNextUpdate )
	{
		freeThreadedMemoryOnNextUpdate = false;
		FreeThreadedMemory();
	}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif
