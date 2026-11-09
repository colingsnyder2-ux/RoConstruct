// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Listener;

struct Owner
{
    void remove(Listener *);
};

struct Count
{
    virtual ~Count();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void *object;
    Count *count;
};

struct Base
{
    virtual ~Base();
};

__forceinline Base::~Base()
{
}

struct Listener : Base
{
    Shared shared;
    Owner *owner;

    virtual ~Listener();
};

Listener::~Listener()
{
    if (owner)
        owner->remove(this);

    Count *p = shared.count;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}
