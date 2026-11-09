// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned __int64 RakNetTimeNS;
typedef unsigned int RakNetTime;
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED, RELIABLE_SEQUENCED };
namespace DataStructures {
template<class T> class List {
public:
    T* listArray; unsigned list_size; unsigned allocation_size;
    ~List() { Clear(); if (allocation_size > 0) delete[] listArray; }
    T& operator[](unsigned i) const { return listArray[i]; }
    unsigned Size() const { return list_size; }
    void Clear() {
        if (allocation_size == 0) return;
        delete[] listArray;
        allocation_size = 0; listArray = 0; list_size = 0;
    }
    void RemoveAtIndex(unsigned position) {
        if (position < list_size) {
            for (unsigned i = position; i < list_size - 1; ++i)
                listArray[i] = listArray[i + 1];
            list_size--;
        }
    }
};
template<class T> class MemoryPool { public: void Release(T* m); };
}
struct InternalPacket {
    char pad[0x14];
    PacketReliability reliability;
    char pad2[0x44 - 0x18];
    unsigned char* data;
};
struct SplitPacketChannel {
    RakNetTimeNS lastUpdateTime;
    DataStructures::List<InternalPacket*> splitPacketList;

};
class ReliabilityLayer {
public:
    char pad0[0xa4];
    DataStructures::List<SplitPacketChannel*> splitPacketChannelList;
    char pad1[0x6d8 - 0xb0];
    RakNetTime timeoutTime;
    char pad2[0x1308 - 0x6dc];
    DataStructures::MemoryPool<InternalPacket> internalPacketPool;
    void DeleteOldUnreliableSplitPackets(RakNetTimeNS time);
};
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
