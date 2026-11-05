// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    void* field4;
    void* field8;
};

struct Outer {
    Inner* field0;
};

struct Target {
};

void __cdecl invoke(Outer* o) {
    Inner* p = o->field0;
    void* a = p->field4;
    void* b = p->field8;
    if (b == 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 8), 1);
    }
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))p;
    fn((char*)p + 12, a, b);
}
