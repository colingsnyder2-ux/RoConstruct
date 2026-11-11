// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// >>> native-status (generated) -- do not edit >>>
// ReliabilityLayer | 2008-06 | selection unverified
// 0/11 mapped addresses reported exact (subset) | no mapped strings | historical| by auto
// <<< native-status | src 5cda2ac1 | roc native-status --write
#include "ReliabilityLayer.h"

bool ReliabilityLayer::AckTimeout(RakNetTimeNS curTime)
{
	return curTime > lastAckTime && lastAckTime && curTime - lastAckTime > (RakNetTimeNS)timeoutTime*1000;
}

RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsDecrease(void) const
{
	return lastTimeBetweenPacketsDecrease;
}

RakNetTimeNS ReliabilityLayer::GetLastTimeBetweenPacketsIncrease(void) const
{
	return lastTimeBetweenPacketsIncrease;
}

bool ReliabilityLayer::IsOutgoingDataWaiting(void)
{
	unsigned i;
	for ( i = 0; i < NUMBER_OF_PRIORITIES; i++ )
	{
		if (sendPacketSet[ i ].Size() > 0)
			return true;
	}


	return acknowlegements.Size() > 0 || resendList.IsEmpty()==false;// || outputQueue.Size() > 0 || orderingList.Size() > 0 || splitPacketChannelList.Size() > 0;
}

bool ReliabilityLayer::AreAcksWaiting(void)
{
	return acknowlegements.Size() > 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class DataStructures::Queue<InternalPacket *>;

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

	// REMOVEME
//	if (internalPacket->messageNumber > 30000)
//	{
//		int a=5;
//	}


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

//	if (internalPacket->reliability == RELIABLE || internalPacket->reliability == RELIABLE_ORDERED || internalPacket->reliability==RELIABLE_SEQUENCED)
	//{
	//	// Write the time in reliable packets for flow control
//		bitStream->Write((RemoteSystemTimeType) (curTime/(RakNetTimeNS)1000));
//	}

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

void ReliabilityLayer::SetUnreliableTimeout(RakNetTime timeoutMS)
{
	unreliableTimeout=(RakNetTimeNS)timeoutMS*(RakNetTimeNS)1000;
}

RakNetTimeNS ReliabilityLayer::GetAckPing(void) const
{
	return ackPing;
}

// Methods recovered from exact mined packets: field offsets mapped to this header by compiler layout.
unsigned int ReliabilityLayer::GetTimeoutTime() { return timeoutTime; }
bool ReliabilityLayer::IsCheater() const { return cheater; }
bool ReliabilityLayer::IsDeadConnection() const { return deadConnection; }
