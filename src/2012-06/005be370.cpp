// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RakNet::RakPeer::PushBackPacket, standalone with the 2012-06 layout (packetReturnMutex at 0x5a0,
// packetReturnQueue at 0x5b8) and the 2012-06 __LINE__ values (0x9e8 = 2536, 0x9ea = 2538).
extern const char rakPeerFile[]; // the build machine's __FILE__ string for RakPeer.cpp
typedef unsigned int BitSize_t;
struct SimpleMutex { void Lock(); void Unlock(); };
struct SystemAddress { unsigned int address[4]; unsigned short debugPort; unsigned short systemIndex; };
struct Packet {
    SystemAddress systemAddress;
    char guid[0x14];
    unsigned int length;
    BitSize_t bitSize;
    unsigned char* data;
};
struct PluginInterface2 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void OnPushBackPacket(const char* data, const BitSize_t bitsUsed, SystemAddress remoteSystemAddress);
};
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
};
void* rakRealloc(void* p, unsigned n, const char* file, unsigned line);
template<class T> struct Queue {
    T* array; unsigned head; unsigned tail; unsigned allocation_size;
    unsigned Size() const { return head <= tail ? tail - head : allocation_size - head + tail; }
    void Push(const T& input, const char* file, unsigned int line);
    void PushAtHead(const T& input, unsigned index, const char* file, unsigned int line);
};
// The out-of-line bodies are visible in the vendor unit; that visibility is what lets the
// compiler keep `packet` in a register although its address is passed to them.
template<class T> void Queue<T>::Push(const T& input, const char* file, unsigned int line)
{
    if (allocation_size == 0) {
        array = (T*)rakRealloc(0, 16 * sizeof(T), file, line);
        head = 0;
        tail = 1;
        array[0] = input;
        allocation_size = 16;
        return;
    }
    array[tail++] = input;
    if (tail == allocation_size)
        tail = 0;
    if (tail == head) {
        T* new_array = (T*)rakRealloc(0, allocation_size * 2 * sizeof(T), file, line);
        if (new_array == 0)
            return;
        for (unsigned counter = 0; counter < allocation_size; ++counter)
            new_array[counter] = array[(head + counter) % allocation_size];
        head = 0;
        tail = allocation_size;
        allocation_size *= 2;
        rakRealloc(array, 0, file, line);
        array = new_array;
    }
}
template<class T> void Queue<T>::PushAtHead(const T& input, unsigned index, const char* file, unsigned int line)
{
    Push(input, file, line);
    if (Size() == 1)
        return;
    unsigned writeIndex, readIndex, trueWriteIndex, trueReadIndex;
    writeIndex = Size() - 1;
    readIndex = writeIndex - 1;
    while (readIndex >= index) {
        if (head + writeIndex >= allocation_size) trueWriteIndex = head + writeIndex - allocation_size;
        else trueWriteIndex = head + writeIndex;
        if (head + readIndex >= allocation_size) trueReadIndex = head + readIndex - allocation_size;
        else trueReadIndex = head + readIndex;
        array[trueWriteIndex] = array[trueReadIndex];
        if (readIndex == 0) break;
        writeIndex--;
        readIndex--;
    }
    if (head + index >= allocation_size) trueWriteIndex = head + index - allocation_size;
    else trueWriteIndex = head + index;
    array[trueWriteIndex] = input;
}
struct RakPeerInterface { virtual void PushBackPacket(Packet* packet, bool pushAtHead) = 0; };
struct RakPeer : RakPeerInterface {
    char pad[0x2cc - 4];
    List<PluginInterface2*> pluginListTS, pluginListNTS;
    char pad2[0x5a0 - 0x2e4];
    SimpleMutex packetReturnMutex;
    char pad3[0x5b8 - 0x5a1];
    Queue<Packet*> packetReturnQueue;
    virtual void PushBackPacket(Packet* packet, bool pushAtHead);
};
void RakPeer::PushBackPacket(Packet* packet, bool pushAtHead)
{
    if (packet == 0)
        return;

    unsigned i;
    for (i = 0; i < pluginListTS.Size(); i++)
        pluginListTS[i]->OnPushBackPacket((const char*)packet->data, packet->bitSize, packet->systemAddress);
    for (i = 0; i < pluginListNTS.Size(); i++)
        pluginListNTS[i]->OnPushBackPacket((const char*)packet->data, packet->bitSize, packet->systemAddress);

    packetReturnMutex.Lock();
    if (pushAtHead)
        packetReturnQueue.PushAtHead(packet, 0, rakPeerFile, 2536);
    else
        packetReturnQueue.Push(packet, rakPeerFile, 2538);
    packetReturnMutex.Unlock();
}