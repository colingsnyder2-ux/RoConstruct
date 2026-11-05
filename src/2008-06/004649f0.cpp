// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" {
extern void (__stdcall *EnterCriticalSection)(void*);
extern void (__stdcall *LeaveCriticalSection)(void*);
}

struct Pair
{
    unsigned long first;
    unsigned long second;

    __forceinline Pair(const Pair&);
    __forceinline ~Pair();
};

__forceinline Pair::Pair(const Pair& other)
{
    second = other.second;
    first = other.first;
}

__forceinline Pair::~Pair()
{
}

struct Context
{
    unsigned char reserved[0x2c];
    unsigned char criticalSection[24];
};

struct S
{
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void invoke(void*, Pair);

    unsigned char reserved[0x1c];
    Context* context;

    void f(void*, Pair);
};

void S::f(void* argument, Pair value)
{
    void* lock = context->criticalSection;
    EnterCriticalSection(lock);
    invoke(argument, value);
    LeaveCriticalSection(lock);
}
