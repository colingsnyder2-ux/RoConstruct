// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#define _FILE_AND_LINE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", __LINE__
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
namespace RakNet {
extern void (*rakFree_Ex)(void*, const char*, unsigned int);
template <class Type> void OP_DELETE(Type* buff, const char* file, unsigned int line);
class SimpleMutex { public: void Lock(); void Unlock(); char d[0x18]; };
struct SystemAddress {
    int data[5];
    SystemAddress& operator=(const SystemAddress& input);
    bool operator==(const SystemAddress& right) const;
};
struct RakNetGUID { unsigned long long g; unsigned short systemIndex; RakNetGUID& operator=(const RakNetGUID& input) { g = input.g; systemIndex = input.systemIndex; return *this; } };
struct Packet {
    SystemAddress systemAddress;
    RakNetGUID guid;
    char pad[0x30 - 0x28];
    unsigned char* data;
    bool deleteData;
};
}
namespace DataStructures {
template <class T> class MemoryPool {
public:
    void Release(T* m, const char* file, unsigned int line);
};
template <class T> class ThreadsafeQ {
public:
    void Push(const T& input, const char* file, unsigned int line);
};
template <class queue_type> class Queue {
public:
    queue_type* array;
    unsigned int head;
    unsigned int tail;
    unsigned int allocation_size;
    inline unsigned int Size(void) const
    {
        if (head <= tail)
            return tail - head;
        else
            return allocation_size - head + tail;
    }
    inline queue_type& operator[](unsigned int position) const
    {
        if (head + position >= allocation_size)
            return array[head + position - allocation_size];
        else
            return array[head + position];
    }
    void RemoveAtIndex(unsigned int position);
};
}
namespace RakNet {
class RakPeer {
public:
    virtual void v0();
    virtual void SendLoopback(const char* data, const int length);
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void PushBackPacket(Packet* packet, bool pushAtHead);
    Packet* AllocPacket(unsigned dataSize, const char* file, unsigned int line);
    SystemAddress GetLoopbackAddress(void) const;
    char pad0[0x458 - 8];
    RakNetGUID myGuid;
    char pad1[0x498 - 0x468];
    SystemAddress ipList[1];
};
#line 1177
void RakPeer::SendLoopback( const char *data, const int length )
{
	if ( data == 0 || length < 0 )
		return;

	Packet *packet = AllocPacket(length, _FILE_AND_LINE_);
	memcpy(packet->data, data, length);
	packet->systemAddress = GetLoopbackAddress();
	packet->guid=myGuid;
	PushBackPacket(packet, false);
}
SystemAddress RakPeer::GetLoopbackAddress(void) const
{
	return ipList[0];
}
}
