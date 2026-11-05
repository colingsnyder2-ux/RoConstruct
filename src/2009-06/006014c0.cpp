// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    long ref;
    char pad[8];
    long ref2;
};

struct Outer {
    char pad0[8];
    Inner* p;
};

struct S {
    void __cdecl f(Outer* a, Outer* b, Outer* c);
};

void sub_601410(Inner* p);

void S::f(Outer* a, Outer* b, Outer* c)
{
    Inner* x = a->p;
    Inner* y = b->p;
    Inner* z = c->p;
    if (z) {
        _InterlockedExchangeAdd(&z->ref, 1);
    }
    sub_601410(x);
    if (y) {
        if (_InterlockedExchangeAdd(&y->ref, -1) == 1) {
            void** vt = *(void***)y;
            ((void (__thiscall*)(Inner*))vt[1])(y);
            if (_InterlockedExchangeAdd(&y->ref2, -1) == 1) {
                ((void (__thiscall*)(Inner*))vt[2])(y);
            }
        }
    }
}
