// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Handle
{
    Control* value;
    void assign(const Handle&);
};

struct Shared
{
    void* value;
    Handle handle;

    ~Shared();
    Shared& operator=(const Shared&);
    void reset();
};

inline Shared::~Shared()
{
    if (handle.value)
    {
        Control* p = handle.value;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

inline Shared& Shared::operator=(const Shared& other)
{
    value = other.value;
    handle.assign(other.handle);
    return *this;
}

extern unsigned char descriptor;
extern "C" void* __stdcall lookup(void*, int, const void*);
extern "C" void* __cdecl convert(void*);
Shared __cdecl makeShared(void*);

struct S
{
    unsigned char padding[28];
    Shared selected;
    void f(void*);
};

void S::f(void* argument)
{
    void* p = lookup(argument, 0, &descriptor);
    if (p)
        selected = makeShared(convert(p));
    else
        selected.reset();
}
