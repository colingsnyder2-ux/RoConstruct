// from server: 100% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

void* __cdecl operator new(unsigned int) throw();

struct RefCount {
    long reserved;
    volatile long count;

    void addRef() throw();
};

__forceinline void RefCount::addRef() throw()
{
    volatile long* p = &count;
    _ReadWriteBarrier();
    _InterlockedExchangeAdd(p, 1);
}

struct Bundle {
    void* first;
    RefCount* firstCount;
    void* second;
    RefCount* secondCount;

    Bundle(const Bundle& other) throw();
    ~Bundle() throw();
};

__forceinline Bundle::Bundle(const Bundle& other) throw()
{
    first = other.first;
    firstCount = other.firstCount;
    if (firstCount)
        firstCount->addRef();

    second = other.second;
    secondCount = other.secondCount;
    if (secondCount)
        secondCount->addRef();
}

struct Listener;

struct Node {
    char storage[32];
    Node(Listener* owner, int arg, Bundle value) throw();
};

struct Queue {
    char storage[28];
    void append(int* value) throw();
};

struct Messenger {
    void* field0;
    void* field4;
    void method(int arg) throw();
};

struct Listener {
    int reserved;
    Queue queue;
    Messenger* messenger;

    void method(int arg, Bundle value) throw();
};

void Listener::method(int arg, Bundle value) throw()
{
    int node = reinterpret_cast<int>(new Node(this, arg, value));
    arg = node;
    queue.append(&arg);
    messenger->method(node);
}
