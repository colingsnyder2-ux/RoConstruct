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

struct Shared
{
    void* object;
    Control* control;
    __forceinline ~Shared();
};

struct Weak
{
    void* object;
    Control* control;
    __forceinline ~Weak();
};

struct Registry
{
    void remove(void*);
};

struct Base
{
    unsigned long reserved[2];
    virtual ~Base();
};

struct Secondary
{
    virtual void unused();
};

struct S : Base, Secondary
{
    Shared shared;
    Weak weak;
    virtual void unused();
    ~S();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

__forceinline Weak::~Weak()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->weak) == 0)
        p->destroy();
}

__forceinline Base::~Base()
{
}

S::~S()
{
    if (shared.object)
        reinterpret_cast<Registry*>(
            static_cast<char*>(shared.object) + 0x130
        )->remove(static_cast<Secondary*>(this));
}
