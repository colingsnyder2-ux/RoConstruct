// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    RefCount* control;
    ~Shared();
};

inline Shared::~Shared()
{
    RefCount* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Base
{
    unsigned char storage[32];
    ~Base();
};

struct Member
{
    ~Member();
};

struct S : Base
{
    Shared shared;
    unsigned char storage[12];
    Member member;
    ~S();
};

S::~S()
{
}
