// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Container {
    char pad[4];
    unsigned int* begin;
    unsigned int* end;
};

struct Obj {
    char pad0[0xc0];
    Container* container;
};

struct Inner {
    void* vptr;
};

extern "C" void* __stdcall sub_630d36(void*, void*, void*, void*, void*);
extern "C" void sub_573890();
extern "C" void sub_5b6cb0();
extern "C" void sub_5b9120();
extern "C" void sub_5b9270();
extern "C" void sub_55f400();
extern "C" void __stdcall invalid_parameter_noinfo();

struct S {
    void f(void* a, int b);
};

void S::f(void* a, int b)
{
    void* p = sub_630d36(a, (void*)0x881f4c, (void*)0x884a28, 0, 0);
    if (p) {
        void* q = ((void* (*)(void*))sub_573890)(p);
        for (int i = 0; i < 6; ++i) {
            void* r = ((void* (*)(void*, int))sub_5b6cb0)(q, i);
            int v = ((int (*)(void*))sub_5b9120)(r);
            if (v == 2) {
                void* s = ((void* (*)(void*, int))sub_5b6cb0)(q, i);
                ((void (*)(void*, int))sub_5b9270)(s, 3);
            }
        }
    }
    Obj* o = (Obj*)a;
    if (o->container) {
        Container* c = o->container;
        unsigned int* e = c->end;
        if (c->begin > e) {
            invalid_parameter_noinfo();
        }
        Container* c2 = o->container;
        unsigned int* b2 = c2->begin;
        if (b2 > c2->end) {
            invalid_parameter_noinfo();
        }
        ((void (*)(void*, void*, unsigned int*, unsigned int*, void*, void*, void*))sub_55f400)(
            c2, (void*)0x55f460, b2, e, (void*)b, (void*)0x55f460, (void*)0x55f460);
    }
    RefCounted* rc = (RefCounted*)a;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            ((void (*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                ((void (*)(void*))rc->vptr)(rc);
            }
        }
    }
}
