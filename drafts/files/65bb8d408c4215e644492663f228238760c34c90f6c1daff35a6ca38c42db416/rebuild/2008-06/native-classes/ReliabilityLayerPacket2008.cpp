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
// FUNCTION: ROBLOX 0x004e5860
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




