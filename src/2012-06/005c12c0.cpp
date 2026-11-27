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
struct RakNetGUID { unsigned long long g; unsigned short systemIndex; };
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
struct RequestedConnectionStruct { SystemAddress systemAddress; };
class RakPeer {
public:
    virtual void CancelConnectionAttempt(const SystemAddress target);
    char pad0[0x2e4 - 4];
    DataStructures::Queue<RequestedConnectionStruct*> requestedConnectionQueue;
    SimpleMutex requestedConnectionQueueMutex;
};
#line 1478
void RakPeer::CancelConnectionAttempt( const SystemAddress target )
{
	unsigned int i;

	// Cancel pending connection attempt, if there is one
	i=0;
	requestedConnectionQueueMutex.Lock();
	while (i < requestedConnectionQueue.Size())
	{
		if (requestedConnectionQueue[i]->systemAddress==target)
		{
#if LIBCAT_SECURITY==1
			x
			x
#endif
			RakNet::OP_DELETE(requestedConnectionQueue[i], _FILE_AND_LINE_ );
			requestedConnectionQueue.RemoveAtIndex(i);
			break;
		}
		else
			i++;
	}
	requestedConnectionQueueMutex.Unlock();

}
}
