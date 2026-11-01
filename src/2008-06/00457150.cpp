// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__stdcall *EnterCriticalSection)(void*);
extern "C" void (__stdcall *LeaveCriticalSection)(void*);

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Pair
{
    void* object;
    Control* control;

    Pair(const Pair&);
    ~Pair();
};

__forceinline Pair::~Pair()
{
}

struct S;
typedef void (__thiscall *Handler)(S*, void*, Pair);

struct S
{
    Handler* table;
    unsigned char reserved[28];
    unsigned char* owner;

    void f(void*, Pair);
};

void S::f(void* argument, Pair value)
{
    void* lock = owner + 44;
    EnterCriticalSection(lock);
    Handler* slot = table + 3;
    (*slot)(this, argument, value);
    LeaveCriticalSection(lock);

    if (value.control)
    {
        Control* control = value.control;
        if (_InterlockedDecrement(&control->strong) == 0)
        {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }
}

