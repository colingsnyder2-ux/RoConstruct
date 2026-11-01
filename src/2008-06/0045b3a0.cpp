// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct ControlBlock {
    int reserved;
    volatile long references;
};

struct Shared {
    void* object;
    ControlBlock* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct First {
    virtual ~First();
    char storage[0x48];

    First(Shared);
};

struct Second {
    virtual ~Second();
    char storage[0x140];

    Second(void*);
};

struct CRobloxWnd {
    char padding0[0x70];
    Shared shared;
    char padding1[0x38];
    First* first;
    Second* second;
    void* argument;

    void sub_45b3a0();
};

void CRobloxWnd::sub_45b3a0()
{
    First* replacementFirst = new First(shared);
    if (replacementFirst != first && first)
        delete first;
    first = replacementFirst;

    Second* replacementSecond = new Second(argument);
    if (replacementSecond != second && second)
        delete second;
    second = replacementSecond;
}
