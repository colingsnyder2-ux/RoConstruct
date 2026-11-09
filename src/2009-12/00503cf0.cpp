// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_4FA630(void*, void*, unsigned char);
extern "C" void __cdecl sub_500A10();

struct RefCounted {
    void* vptr;
    long refcount;
    long refcount2;
};

struct S {
    void f(void* a, void* b, void* c);
};

void S::f(void* a, void* b, void* c)
{
    RefCounted* p = (RefCounted*)c;
    void* local[2];
    local[0] = a;
    local[1] = b;
    if (p) {
        _InterlockedExchangeAdd(&p->refcount, 1);
    }
    sub_4FA630(local, (void*)0x66a720, *(unsigned char*)0xb7e5a5);
    sub_500A10();
    if (p) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))p->vptr)(p);
            if (_InterlockedExchangeAdd(&p->refcount2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)p->vptr)[2])(p);
            }
        }
    }
}
