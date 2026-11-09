// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct ControlBlock
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct SharedHandle
{
    void* object;
    ControlBlock* control;
    ~SharedHandle();
};

inline SharedHandle::~SharedHandle()
{
    ControlBlock* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base
{
    char storage[0x148];
    ~Base();
};

struct Tail
{
    ~Tail();
};

struct LocalBackpackItem : Base
{
    SharedHandle handle;
    Tail tail;
    ~LocalBackpackItem();
};

LocalBackpackItem::~LocalBackpackItem()
{
}
