// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

void* __cdecl operator new(unsigned int size) throw();

struct RefCount
{
    long unused;
    volatile long count;
};

struct Payload
{
    void* first;
    RefCount* firstCount;
    void* second;
    RefCount* secondCount;

    Payload(const Payload& other) throw();
    ~Payload() throw();
};

__forceinline Payload::Payload(const Payload& other) throw()
{
    first = other.first;
    firstCount = other.firstCount;
    if (firstCount)
    {
        volatile long* count = &firstCount->count;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }

    second = other.second;
    secondCount = other.secondCount;
    if (secondCount)
    {
        volatile long* count = &secondCount->count;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
}

struct S;

struct Node
{
    unsigned char storage[32];
    Node(S* owner, int arg, Payload value) throw();
};

struct Queue
{
    unsigned char storage[28];
    void insert(void* const& node) throw();
};

struct Poster
{
    void* field0;
    void* field4;
    void method(int arg) throw();
};

struct S
{
    void* field0;
    Queue queue;
    Poster* poster;

    void func_00466440(int arg, Payload value);
};

void S::func_00466440(int arg, Payload value)
{
    Node* node = new Node(this, arg, value);
    queue.insert(node);
    poster->method(reinterpret_cast<int>(node));
}
