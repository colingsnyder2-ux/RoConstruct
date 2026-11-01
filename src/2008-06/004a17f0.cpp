// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void* __cdecl dynamicCast(void*, long, void*, void*, int);
extern unsigned char instanceType[];
extern unsigned char replicatorType[];

struct ControlBlock {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strongCount;
    volatile long weakCount;
};

struct Shared {
    void* object;
    ControlBlock* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    ControlBlock* p = control;
    if (p && _InterlockedDecrement(&p->strongCount) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weakCount) == 0)
            p->destroy();
    }
}

bool __cdecl f(Shared value)
{
    return dynamicCast(value.object, 0, instanceType, replicatorType, 0) != 0;
}
