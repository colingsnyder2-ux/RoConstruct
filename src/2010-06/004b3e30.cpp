// from server: 13% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Arg {
    int a;
    int b;
};

struct Inner {
    void* vptr;
    volatile long ref;
};

extern void func_004b3b70(void*, void*);
extern void func_004b3c70(void*);
extern void func_004ab4b0(void*);

struct SignalSlot {
    void func(Arg* arg, void* p);
};

void SignalSlot::func(Arg* arg, void* p)
{
    void* local;
    void* sp20;
    RefCounted* obj;
    Inner* inner;
    void* saved;

    func_004b3b70(&local, arg);
    sp20 = 0;
    obj = (RefCounted*)p;
    if (obj != 0) {
        _InterlockedExchangeAdd(&obj->ref1, 1);
    }
    func_004b3c70(this);
    inner = (Inner*)sp20;
    if (inner != 0) {
        if (_InterlockedExchangeAdd(&inner->ref, -1) == 1) {
            ((void (__thiscall*)(Inner*))inner->vptr)(inner);
        }
    }
    func_004ab4b0(&local);
}
