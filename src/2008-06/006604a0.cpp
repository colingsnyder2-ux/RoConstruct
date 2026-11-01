// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Reference
{
    Control* control;
    Reference();
    ~Reference();
    Reference& operator=(const Reference&);
};

struct Pointer
{
    void* object;
    Reference reference;
    Pointer();
    Pointer& operator=(const Pointer&);
};

Pointer __cdecl makePointer(void*);

struct S
{
    unsigned long table;
    Pointer pointer;
    S(void*);
};

__forceinline Reference::Reference() : control(0)
{
}

__forceinline Reference::~Reference()
{
    Control* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Pointer::Pointer() : object(0)
{
}

__forceinline Pointer& Pointer::operator=(const Pointer& other)
{
    object = other.object;
    reference = other.reference;
    return *this;
}

S::S(void* argument) : table(0x0084c46c)
{
    pointer = makePointer(argument);
}
