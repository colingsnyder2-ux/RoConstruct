// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* f_0;
    char pad_4[0x18];
    volatile long refcount;
};

struct LocalScript {
    virtual void* getSomething();
};

void __cdecl sub_4b20f0(void*, void*);

void LocalScript_release(LocalScript* self) {
    void* obj = self->getSomething();
    RefCounted* rc = (RefCounted*)obj;
    if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
        sub_4b20f0((void*)0x4b1bc0, &obj);
    }
}
