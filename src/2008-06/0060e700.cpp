// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void dispose();
    virtual void release();
    virtual void destroy();
    long strongCount;
    volatile long weakCount;
};

struct Weak {
    void* object;
    Control* control;
    ~Weak();
};

struct Sub {
    char data[24];
    ~Sub();
};

extern void __cdecl cleanup(Sub*);

struct S {
    Weak weak;
    Sub sub;
    bool flag;
    ~S();
};

inline Weak::~Weak()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->weakCount) == 0)
        p->destroy();
}

S::~S()
{
    if (!flag)
        cleanup(&sub);
}
