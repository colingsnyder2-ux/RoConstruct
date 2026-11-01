// from server: 99% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
typedef unsigned int SOCKET;
typedef unsigned int RakNetTime;
extern "C" __declspec(dllimport) int __stdcall closesocket(SOCKET);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace RakNet { RakNetTime GetTime(); }
void RakSleep(unsigned int ms);

struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
class ReliabilityLayer { public: void Reset(bool resetVariables); };
struct RemoteSystemStruct {
    bool isActive;
    SystemAddress systemAddress;
    char pad0[0x30 - 0xc];
    ReliabilityLayer reliabilityLayer;
    char pad1[0x13d0 - 0x31];
    ~RemoteSystemStruct();
};
class RakPeer;
class PluginInterface {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void OnShutdown(RakPeer* peer);
};
struct Packet;
namespace DataStructures {
template<class T> class List {
public:
    T* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    T& operator[](unsigned int i) const { return listArray[i]; }
    unsigned int Size() const { return list_size; }
    void Clear() {
        if (allocation_size == 0) return;
        delete[] listArray;
        allocation_size = 0;
        listArray = 0;
        list_size = 0;
    }
};
template<class T> class Queue {
public:
    T* array;
    unsigned int head;
    unsigned int tail;
    unsigned int allocation_size;
    unsigned int Size() const { if (head <= tail) return tail - head; else return allocation_size - head + tail; }
    T& operator[](unsigned int position) const {
        if (head + position >= allocation_size) return array[head + position - allocation_size];
        else return array[head + position];
    }
    void Clear() {
        if (allocation_size == 0) return;
        if (allocation_size > 32) { delete[] array; allocation_size = 0; }
        head = 0;
        tail = 0;
    }
};
template<class T> class SingleProducerConsumer {
public:
    struct DataPlusPtr { T object; volatile bool readyToRead; DataPlusPtr* next; };
    DataPlusPtr* readAheadPointer;
    DataPlusPtr* writeAheadPointer;
    DataPlusPtr* readPointer;
    DataPlusPtr* writePointer;
    unsigned readCount;
    unsigned writeCount;
    T* ReadLock() {
        if (readAheadPointer != writePointer && readAheadPointer->readyToRead) {
            DataPlusPtr* last = readAheadPointer;
            readAheadPointer = readAheadPointer->next;
            return (T*)last;
        }
        return 0;
    }
    void ReadUnlock() {
        readCount++;
        readPointer->readyToRead = false;
        readPointer = readPointer->next;
    }
    void Clear();
};
}
struct SocketEntry { SOCKET s; char a; bool owned; short b; };

class RakPeer {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void DeallocatePacket(Packet* packet);
    virtual void Shutdown(unsigned int blockDuration, unsigned char orderingChannel);

    volatile bool endThreads;
    volatile bool isMainLoopThreadActive;
    short pad6;
    unsigned short maximumNumberOfPeers;
    char pad0[0x53c - 0xa];
    RemoteSystemStruct* remoteSystemList;
    DataStructures::List<int> remoteSystemLookup;
    char pad1[0x56c - 0x54c];
    unsigned int bytesSentPerSecond;
    unsigned int bytesReceivedPerSecond;
    char pad2[0x5bc - 0x574];
    DataStructures::List<PluginInterface*> messageHandlerList;
    char pad3[0xa58 - 0x5c8];
    SocketEntry* connectionSockets;
    unsigned int connectionSocketsLength;
    void* recvEvent;
    char pad4[0xa78 - 0xa64];
    bool blockOnRPCReply;
    char pad5[0xb58 - 0xa79];
    DataStructures::SingleProducerConsumer<Packet*> packetSingleProducerConsumer;
    DataStructures::Queue<Packet*> packetPool;

    void NotifyAndFlagForShutdown(const SystemAddress systemAddress, bool performImmediate, unsigned char orderingChannel);
    void ClearBufferedCommands();
    void ClearRequestedConnectionList();
};

void RakPeer::Shutdown(unsigned int blockDuration, unsigned char orderingChannel)
{
    unsigned i, j;
    bool anyActive;
    RakNetTime startWaitingTime;
    RakNetTime time;
    unsigned short systemListSize = maximumNumberOfPeers;

    if (blockDuration > 0)
    {
        for (i = 0; i < systemListSize; i++)
        {
            if (remoteSystemList[i].isActive)
                NotifyAndFlagForShutdown(remoteSystemList[i].systemAddress, false, orderingChannel);
        }

        time = RakNet::GetTime();
        startWaitingTime = time;
        while (time - startWaitingTime < blockDuration)
        {
            anyActive = false;
            for (j = 0; j < systemListSize; j++)
            {
                if (remoteSystemList[j].isActive)
                {
                    anyActive = true;
                    break;
                }
            }
            if (anyActive == false)
                break;
            RakSleep(15);
            time = RakNet::GetTime();
        }
    }

    for (i = 0; i < messageHandlerList.Size(); i++)
        messageHandlerList[i]->OnShutdown(this);

    while (isMainLoopThreadActive)
    {
        endThreads = true;
        RakSleep(15);
    }

    for (i = 0; i < systemListSize; i++)
    {
        remoteSystemList[i].isActive = false;
        remoteSystemList[i].reliabilityLayer.Reset(false);
    }

    remoteSystemLookup.Clear();
    maximumNumberOfPeers = 0;

    Packet** packet;
    packet = packetSingleProducerConsumer.ReadLock();
    while (packet)
    {
        DeallocatePacket(*packet);
        packetSingleProducerConsumer.ReadUnlock();
        packet = packetSingleProducerConsumer.ReadLock();
    }
    packetSingleProducerConsumer.Clear();

    for (i = 0; i < packetPool.Size(); i++)
        DeallocatePacket(packetPool[i]);
    packetPool.Clear();

    blockOnRPCReply = false;

    for (i = 0; i < connectionSocketsLength; i++)
        if (connectionSockets[i].owned)
            closesocket(connectionSockets[i].s);
    if (connectionSockets)
        delete[] connectionSockets;
    connectionSockets = 0;
    connectionSocketsLength = 0;

    ClearBufferedCommands();
    bytesSentPerSecond = bytesReceivedPerSecond = 0;

    ClearRequestedConnectionList();

    if (recvEvent != (void*)-1)
    {
        CloseHandle(recvEvent);
        recvEvent = (void*)-1;
    }

    RemoteSystemStruct* temp = remoteSystemList;
    remoteSystemList = 0;
    delete[] temp;
}
