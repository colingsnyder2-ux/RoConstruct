// from server: 51% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void (*fn)();
    void* field4;
    void* field8;
    char padC[4];
};

struct Outer {
    Inner* ptr;
};

struct S {
    void f(Outer* o);
};

void S::f(Outer* o)
{
    Inner* p = o->ptr;
    void* a = p->field4;
    void* b = p->field8;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 8), 1);
    }
    p->fn();
}
