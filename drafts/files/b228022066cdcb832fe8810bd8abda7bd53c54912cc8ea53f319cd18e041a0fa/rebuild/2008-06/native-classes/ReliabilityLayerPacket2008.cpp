// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// RakNet packet methods: inactive drafts pending class integration.
#include "../native-headers/ReliabilityLayer.h"
#include "GetTime.h"
#include "MessageIdentifiers.h"
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
//		printf( "Error!! ReliabilityLayer::Send bitStream->GetNumberOfBytesUsed()==0\n" );
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

//	printf("%i\n", messageNumber);
	//internalPacket->messageNumber = sendMessageNumberIndex;
	internalPacket->messageNumber = (MessageNumberType) -1;
	internalPacket->messageNumberAssigned=false;

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

//	++sendMessageNumberIndex;

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
