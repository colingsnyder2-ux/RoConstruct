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
    void* pointer;
    Control* control;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : pointer(0), control(0)
{
}

inline Shared::~Shared()
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

struct Base
{
    virtual ~Base();
};

struct S : Base
{
    Shared connection;
    void* owner;
    Shared listener;

    S(void*, void*, Shared);
    virtual ~S();
    void attach(void*);
};

S::S(void* a, void* b, Shared value)
    : owner(a), listener(value)
{
    attach(b);
}
