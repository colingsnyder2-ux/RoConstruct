// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
typedef __int64 RakNetTimeNS;
struct InternalPacket
{
	unsigned messageNumber;
	bool messageNumberAssigned;
	unsigned packetNumber;
	unsigned exeField;
	int priority;
	int reliability;
	unsigned char orderingChannel;
	unsigned orderingIndex;
	unsigned short splitPacketId;
	unsigned splitPacketIndex;
	unsigned splitPacketCount;
	RakNetTimeNS creationTime;
	RakNetTimeNS nextActionTime;
	unsigned int dataBitLength;
	unsigned char *data;
};
namespace DataStructures {
template <class queue_type> class Queue {
public:
	unsigned int Size( void ) const
	{
		if ( head <= tail )
			return tail -head;
		else
			return allocation_size -head + tail;
	}
	queue_type Pop( void )
	{
		if ( ++head == allocation_size )
			head = 0;
		if ( head == 0 )
			return ( queue_type ) array[ allocation_size -1 ];
		return ( queue_type ) array[ head -1 ];
	}
	queue_type* array;
	unsigned int head;
	unsigned int tail;
	unsigned int allocation_size;
};
template <class MemoryBlockType> class MemoryPool {
public:
	void Release(MemoryBlockType* m);
};
}
class ReliabilityLayer {
public:
	int Receive( unsigned char **data );
	char pad0[0xc];
	DataStructures::Queue<InternalPacket*> outputQueue;
	char pad1[0x12d4-0x1c];
	bool freeThreadedMemoryOnNextUpdate;
	char pad2[0x1308-0x12d5];
	DataStructures::MemoryPool<InternalPacket> internalPacketPool;
};
int ReliabilityLayer::Receive( unsigned char **data )
{
	if (freeThreadedMemoryOnNextUpdate)
		return 0;
	InternalPacket * internalPacket;
	if ( outputQueue.Size() > 0 )
	{
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
