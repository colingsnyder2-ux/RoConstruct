// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>
typedef __int64 RakNetTimeNS;
typedef unsigned short SplitPacketIdType;
typedef unsigned int SplitPacketIndexType;
typedef unsigned int MessageNumberType;
enum PacketPriority { SYSTEM_PRIORITY };
enum PacketReliability { UNRELIABLE };
#define BITS_TO_BYTES(x) (((x)+7)>>3)
namespace RakNet {
extern void* (*rakMalloc)(size_t size);
extern void (*rakFree)(void* p);
template <class Type> void OP_DELETE(Type *buff, const char *file, unsigned int line) { delete buff; }
}
struct InternalPacket
{
	MessageNumberType messageNumber;
	bool messageNumberAssigned;
	unsigned packetNumber;
	unsigned exeField;
	PacketPriority priority;
	PacketReliability reliability;
	unsigned char orderingChannel;
	MessageNumberType orderingIndex;
	SplitPacketIdType splitPacketId;
	SplitPacketIndexType splitPacketIndex;
	SplitPacketIndexType splitPacketCount;
	RakNetTimeNS creationTime;
	RakNetTimeNS nextActionTime;
	unsigned int dataBitLength;
	unsigned char *data;
};
namespace DataStructures {
template <class list_type> class List {
public:
	list_type* listArray;
	unsigned int list_size;
	unsigned int allocation_size;
	~List();
	list_type& operator[](const unsigned int position) const { return listArray[position]; }
	unsigned int Size() const { return list_size; }
	void RemoveFromEnd(const unsigned num=1) { list_size-=num; }
	void RemoveAtIndex(const unsigned int position)
	{
		if ( position < list_size )
		{
			for ( unsigned int counter = position; counter < list_size - 1 ; ++counter )
			listArray[ counter ] = listArray[ counter + 1 ];
			RemoveFromEnd();
		}
	}
	void Clear(bool doNotDeallocateSmallBlocks=false);
};
template <class list_type> List<list_type>::~List() { if (allocation_size>0) delete [] listArray; }
template <class list_type> void List<list_type>::Clear(bool doNotDeallocateSmallBlocks)
	{
		if ( allocation_size == 0 )
			return;
		if (allocation_size>512 || doNotDeallocateSmallBlocks==false)
		{
			delete [] listArray;
			allocation_size = 0;
			listArray = 0;
		}
		list_size = 0;
	}
template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
class OrderedList {
public:
	~OrderedList();
	void Clear(bool doNotDeallocateSmallBlocks=false) { orderedList.Clear(doNotDeallocateSmallBlocks); }
	unsigned GetIndexFromKey(const key_type &key, bool *objectExists, int (*cf)(const key_type&, const data_type&)=default_comparison_function) const;
	data_type& operator[](const unsigned int position) const { return orderedList[position]; }
	unsigned Size() const { return orderedList.Size(); }
	void RemoveAtIndex(const unsigned index) { orderedList.RemoveAtIndex(index); }
	List<data_type> orderedList;
};
template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
OrderedList<key_type, data_type, default_comparison_function>::~OrderedList() { Clear(); }
template <class MemoryBlockType> class MemoryPool {
public:
	MemoryBlockType* Allocate();
	void Release(MemoryBlockType* m);
};
}
int SplitPacketIndexComp( SplitPacketIndexType const &key, InternalPacket* const &data );
struct SplitPacketChannel
{
	RakNetTimeNS lastUpdateTime;
	DataStructures::OrderedList<SplitPacketIndexType, InternalPacket*, SplitPacketIndexComp> splitPacketList;
};
int SplitPacketChannelComp( SplitPacketIdType const &key, SplitPacketChannel* const &data );
class ReliabilityLayer {
public:
	InternalPacket * BuildPacketFromSplitPacketList( SplitPacketIdType splitPacketId, RakNetTimeNS time );
	InternalPacket * CreateInternalPacketCopy( InternalPacket *original, int dataByteOffset, int dataByteLength, RakNetTimeNS time );
	char pad0[0xa4];
	DataStructures::OrderedList<SplitPacketIdType, SplitPacketChannel*, SplitPacketChannelComp> splitPacketChannelList;
	char pad1[0x1308-0xa4-0xc];
	DataStructures::MemoryPool<InternalPacket> internalPacketPool;
};
inline InternalPacket * ReliabilityLayer::CreateInternalPacketCopy( InternalPacket *original, int dataByteOffset, int dataByteLength, RakNetTimeNS time )
{
	InternalPacket * copy = internalPacketPool.Allocate();
	if ( dataByteLength > 0 )
	{
		copy->data = (unsigned char*) RakNet::rakMalloc( dataByteLength );
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
InternalPacket * ReliabilityLayer::BuildPacketFromSplitPacketList( SplitPacketIdType splitPacketId, RakNetTimeNS time )
{
	unsigned i, j;
	unsigned byteProgress;
	InternalPacket * internalPacket;
	bool objectExists;

	i=splitPacketChannelList.GetIndexFromKey(splitPacketId, &objectExists);

	if (splitPacketChannelList[i]->splitPacketList.Size()==splitPacketChannelList[i]->splitPacketList[0]->splitPacketCount)
	{
		internalPacket = CreateInternalPacketCopy( splitPacketChannelList[i]->splitPacketList[0], 0, 0, time );
		internalPacket->dataBitLength=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
			internalPacket->dataBitLength+=splitPacketChannelList[i]->splitPacketList[j]->dataBitLength;

		internalPacket->data = (unsigned char*) RakNet::rakMalloc( BITS_TO_BYTES( internalPacket->dataBitLength ) );

		byteProgress=0;
		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			memcpy(internalPacket->data+byteProgress, splitPacketChannelList[i]->splitPacketList[j]->data, BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength));
			byteProgress+=BITS_TO_BYTES(splitPacketChannelList[i]->splitPacketList[j]->dataBitLength);
		}

		for (j=0; j < splitPacketChannelList[i]->splitPacketList.Size(); j++)
		{
			RakNet::rakFree(splitPacketChannelList[i]->splitPacketList[j]->data);
			internalPacketPool.Release(splitPacketChannelList[i]->splitPacketList[j]);
		}
		RakNet::OP_DELETE(splitPacketChannelList[i], __FILE__, __LINE__);
		splitPacketChannelList.RemoveAtIndex(i);

		return internalPacket;
	}

	return 0;
}
