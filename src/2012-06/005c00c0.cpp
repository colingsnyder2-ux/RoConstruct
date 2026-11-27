// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#define _FILE_AND_LINE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\RakPeer.cpp", __LINE__
extern void (*rakFree_Ex)(void* p, const char* file, unsigned int line);
namespace RakNet {
class SimpleMutex {
public:
    char cs[0x18];
    void Lock();
    void Unlock();
};
}
namespace DataStructures {
template <class queue_type> class Queue {
public:
    queue_type* array;
    unsigned int head;
    unsigned int tail;
    unsigned int allocation_size;
    inline bool IsEmpty(void) const { return head == tail; }
    inline queue_type Pop(void)
    {
        if (++head == allocation_size)
            head = 0;
        if (head == 0)
            return (queue_type)array[allocation_size - 1];
        return (queue_type)array[head - 1];
    }
};
template <class MemoryBlockType> class MemoryPool {
public:
    int state[5];
    void Release(MemoryBlockType* m, const char* file, unsigned int line);
};
template <class structureType> class ThreadsafeAllocatingQueue {
public:
    structureType* Pop(void);
    void Deallocate(structureType* s, const char* file, unsigned int line);
    void Clear(const char* file, unsigned int line);
protected:
    MemoryPool<structureType> memoryPool;
    RakNet::SimpleMutex memoryPoolMutex;
    Queue<structureType*> queue;
    RakNet::SimpleMutex queueMutex;
};
template <class structureType>
structureType* ThreadsafeAllocatingQueue<structureType>::Pop(void)
{
    structureType* s;
    queueMutex.Lock();
    if (queue.IsEmpty())
    {
        queueMutex.Unlock();
        return 0;
    }
    s = queue.Pop();
    queueMutex.Unlock();
    return s;
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
    struct BufferedCommandStruct {
        char pad[0x4c];
        char* data;
    };
    char pad0[0x30c];
    DataStructures::ThreadsafeAllocatingQueue<BufferedCommandStruct> bufferedCommands;
    void ClearBufferedCommands(void);
};
#line 4039
void RakPeer::ClearBufferedCommands(void)
{
    BufferedCommandStruct* bcs;

    while ((bcs = bufferedCommands.Pop()) != 0)
    {
        if (bcs->data)
            rakFree_Ex(bcs->data, _FILE_AND_LINE_);

        bufferedCommands.Deallocate(bcs, _FILE_AND_LINE_);
    }
    bufferedCommands.Clear(_FILE_AND_LINE_);
}
}