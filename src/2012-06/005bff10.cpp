// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
#define _FILE_AND_LINE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", __LINE__
#define BITS_TO_BYTES(x) (((x)+7)>>3)
#define BYTES_TO_BITS(x) ((x)<<3)
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;
typedef uint32_t BitSize_t;
extern void* (*rakMalloc_Ex)(size_t size, const char* file, unsigned int line);
extern void (*rakFree_Ex)(void* p, const char* file, unsigned int line);
extern void (*notifyOutOfMemory)(const char* file, int line);
enum PacketPriority { IMMEDIATE_PRIORITY, HIGH_PRIORITY, MEDIUM_PRIORITY, LOW_PRIORITY, NUMBER_OF_PRIORITIES };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE, RELIABLE_ORDERED, RELIABLE_SEQUENCED };
namespace RakNet {
class SimpleMutex {
public:
    char cs[0x18];
    void Lock();
    void Unlock();
};
class SignaledEvent {
public:
    void SetEvent(void);
};
typedef unsigned short SystemIndex;
struct SystemAddress {
    int data[5];
    SystemAddress& operator=(const SystemAddress& input);
};
struct RakNetGUID {
    uint64_t g;
    SystemIndex systemIndex;
    RakNetGUID& operator=(const RakNetGUID& input)
    {
        g = input.g;
        systemIndex = input.systemIndex;
        return *this;
    }
};
struct AddressOrGUID {
    RakNetGUID rakNetGuid;
    SystemAddress systemAddress;
};
}
namespace DataStructures {
template <class queue_type> class Queue {
public:
    queue_type* array;
    unsigned int head;
    unsigned int tail;
    unsigned int allocation_size;
    void Push(const queue_type& input, const char* file, unsigned int line);
};
template <class MemoryBlockType> class MemoryPool {
public:
    int state[5];
    void Release(MemoryBlockType* m, const char* file, unsigned int line);
};
template <class structureType> class ThreadsafeAllocatingQueue {
public:
    void Push(structureType* s);
    structureType* Allocate(const char* file, unsigned int line);
    void Deallocate(structureType* s, const char* file, unsigned int line);
protected:
    MemoryPool<structureType> memoryPool;
    RakNet::SimpleMutex memoryPoolMutex;
    Queue<structureType*> queue;
    RakNet::SimpleMutex queueMutex;
};
template <class structureType>
void ThreadsafeAllocatingQueue<structureType>::Push(structureType* s)
{
    queueMutex.Lock();
    queue.Push(s, "c:\\teamcity\\buildagent\\work\\8348b47e373515f7\\client\\network\\raknet\\source\\DS_ThreadsafeAllocatingQueue.h", 48);
    queueMutex.Unlock();
}
template <class structureType>
void ThreadsafeAllocatingQueue<structureType>::Deallocate(structureType* s, const char* file, unsigned int line)
{
    s->~structureType();
    memoryPoolMutex.Lock();
    memoryPool.Release(s, file, line);
    memoryPoolMutex.Unlock();
}
}
namespace RakNet {
class RakPeer {
public:
    struct RemoteSystemStruct {
        enum ConnectMode { NO_ACTION, DISCONNECT_ASAP, DISCONNECT_ASAP_SILENTLY, DISCONNECT_ON_NO_ACK,
            REQUESTED_CONNECTION, HANDLING_CONNECTION_REQUEST, UNVERIFIED_SENDER, CONNECTED };
    };
    struct BufferedCommandStruct {
        BitSize_t numberOfBitsToSend;
        PacketPriority priority;
        PacketReliability reliability;
        char orderingChannel;
        AddressOrGUID systemIdentifier;
        bool broadcast;
        RemoteSystemStruct::ConnectMode connectionMode;
        char pad40[0xc];
        char* data;
        char pad50[0x18];
        uint32_t receipt;
        enum { BCS_SEND, BCS_CLOSE_CONNECTION, BCS_GET_SOCKET, BCS_CHANGE_SYSTEM_ADDRESS, BCS_DO_NOTHING } command;
    };
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void SendLoopback(const char* data, const int length);
    char pad0[0x30c - 4];
    DataStructures::ThreadsafeAllocatingQueue<BufferedCommandStruct> bufferedCommands;
    char pad1[0x56c - 0x30c - 0x54];
    SignaledEvent quitAndDataEvents;
    bool IsLoopbackAddress(const AddressOrGUID& systemIdentifier, bool matchPort) const;
    void SendBuffered(const char* data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, const AddressOrGUID systemIdentifier, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode, uint32_t receipt);
    void SendBufferedList(const char** data, const int* lengths, const int numParameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, const AddressOrGUID systemIdentifier, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode, uint32_t receipt);
};
#line 3819
void RakPeer::SendBuffered( const char *data, BitSize_t numberOfBitsToSend, PacketPriority priority, PacketReliability reliability, char orderingChannel, const AddressOrGUID systemIdentifier, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode, uint32_t receipt )
{
	BufferedCommandStruct *bcs;

	bcs=bufferedCommands.Allocate( _FILE_AND_LINE_ );
	bcs->data = (char*) rakMalloc_Ex( (size_t) BITS_TO_BYTES(numberOfBitsToSend), _FILE_AND_LINE_ ); // Making a copy doesn't lose efficiency because I tell the reliability layer to use this allocation for its own copy
	if (bcs->data==0)
	{
		notifyOutOfMemory(_FILE_AND_LINE_);
		bufferedCommands.Deallocate(bcs, _FILE_AND_LINE_);
		return;
	}
	memcpy(bcs->data, data, (size_t) BITS_TO_BYTES(numberOfBitsToSend));
	bcs->numberOfBitsToSend=numberOfBitsToSend;
	bcs->priority=priority;
	bcs->reliability=reliability;
	bcs->orderingChannel=orderingChannel;
	bcs->systemIdentifier=systemIdentifier;
	bcs->broadcast=broadcast;
	bcs->connectionMode=connectionMode;
	bcs->receipt=receipt;
	bcs->command=BufferedCommandStruct::BCS_SEND;
	bufferedCommands.Push(bcs);

	if (priority==IMMEDIATE_PRIORITY)
	{
		// Forces pending sends to go out now, rather than waiting to the next update interval
		quitAndDataEvents.SetEvent();
	}
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void RakPeer::SendBufferedList( const char **data, const int *lengths, const int numParameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, const AddressOrGUID systemIdentifier, bool broadcast, RemoteSystemStruct::ConnectMode connectionMode, uint32_t receipt )
{
	BufferedCommandStruct *bcs;
	unsigned int totalLength=0;
	unsigned int lengthOffset;
	int i;
	for (i=0; i < numParameters; i++)
	{
		if (lengths[i]>0)
			totalLength+=lengths[i];
	}
	if (totalLength==0)
		return;

	char *dataAggregate;
	dataAggregate = (char*) rakMalloc_Ex( (size_t) totalLength, _FILE_AND_LINE_ ); // Making a copy doesn't lose efficiency because I tell the reliability layer to use this allocation for its own copy
	if (dataAggregate==0)
	{
		notifyOutOfMemory(_FILE_AND_LINE_);
		return;
	}
	for (i=0, lengthOffset=0; i < numParameters; i++)
	{
		if (lengths[i]>0)
		{
			memcpy(dataAggregate+lengthOffset, data[i], lengths[i]);
			lengthOffset+=lengths[i];
		}
	}

	if (broadcast==false && IsLoopbackAddress(systemIdentifier,true))
	{
		SendLoopback(dataAggregate,totalLength);
		rakFree_Ex(dataAggregate,_FILE_AND_LINE_);
		return;
	}

	bcs=bufferedCommands.Allocate( _FILE_AND_LINE_ );
	bcs->data = dataAggregate;
	bcs->numberOfBitsToSend=BYTES_TO_BITS(totalLength);
	bcs->priority=priority;
	bcs->reliability=reliability;
	bcs->orderingChannel=orderingChannel;
	bcs->systemIdentifier=systemIdentifier;
	bcs->broadcast=broadcast;
	bcs->connectionMode=connectionMode;
	bcs->receipt=receipt;
	bcs->command=BufferedCommandStruct::BCS_SEND;
	bufferedCommands.Push(bcs);

	if (priority==IMMEDIATE_PRIORITY)
	{
		// Forces pending sends to go out now, rather than waiting to the next update interval
		quitAndDataEvents.SetEvent();
	}
}
}
