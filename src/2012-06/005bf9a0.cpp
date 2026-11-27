// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RakNet {
typedef unsigned short SystemIndex;
struct SystemAddress {
    char body[0x14];
    SystemAddress& operator=(const SystemAddress& input);
};
struct RakNetGUID {
    unsigned __int64 g;
    SystemIndex systemIndex;
    RakNetGUID& operator=(const RakNetGUID& input) { g = input.g; systemIndex = input.systemIndex; return *this; }
};
struct AddressOrGUID {
    RakNetGUID rakNetGuid;
    SystemAddress systemAddress;
};
class SimpleMutex {
public:
    void Lock();
    void Unlock();
};
}
namespace DataStructures {
template <class queue_type>
class Queue {
public:
    void Push(const queue_type& input, const char* file, unsigned int line);
    queue_type* array;
    unsigned int head, tail, allocation_size;
};
template <class structureType>
class ThreadsafeAllocatingQueue {
public:
    void Push(structureType* s);
    structureType* Allocate(const char* file, unsigned int line);
protected:
    char memoryPoolAndMutex[0x2c];
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
}
namespace RakNet {
class RakPeerInterface {
public:
    virtual ~RakPeerInterface();
    virtual void ChangeSystemAddress(RakNetGUID guid, const SystemAddress& systemAddress) = 0;
};
class RakPeer : public RakPeerInterface {
public:
    virtual void ChangeSystemAddress(RakNetGUID guid, const SystemAddress& systemAddress);
    struct BufferedCommandStruct {
        char pad0[0x10];
        AddressOrGUID systemIdentifier;
        char pad38[0x14];
        char* data;
        char pad50[0x1c];
        enum { BCS_SEND, BCS_CLOSE_CONNECTION, BCS_GET_SOCKET, BCS_CHANGE_SYSTEM_ADDRESS, BCS_DO_NOTHING } command;
    };
    char pad4[0x308];
    DataStructures::ThreadsafeAllocatingQueue<BufferedCommandStruct> bufferedCommands;
};
void RakPeer::ChangeSystemAddress(RakNetGUID guid, const SystemAddress& systemAddress)
{
    BufferedCommandStruct* bcs;
    bcs = bufferedCommands.Allocate("C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", 2547);
    bcs->data = 0;
    bcs->systemIdentifier.systemAddress = systemAddress;
    bcs->systemIdentifier.rakNetGuid = guid;
    bcs->command = BufferedCommandStruct::BCS_CHANGE_SYSTEM_ADDRESS;
    bufferedCommands.Push(bcs);
}
}