// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    long ref1;
    long ref2;
};

struct S {
    void* a;
    void* b;
    void f(void* h);
};

extern "C" void __cdecl sub_52FC60(void*, void*);

void S::f(void* h)
{
    void* tmp[2];
    sub_52FC60(tmp, h);
    if (tmp != (void**)this) {
        void* t = *(void**)this;
        void* u = tmp[0];
        tmp[0] = t;
        *(void**)this = u;
    }
    void* c = *(void**)((char*)this + 4);
    void* d = tmp[1];
    *(void**)((char*)this + 4) = d;
    tmp[1] = c;

    Inner* esi = (Inner*)tmp[0];
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            void* vt = esi->vptr;
            void (*fn)(Inner*) = *(void (**)(Inner*))((char*)vt + 4);
            fn(esi);
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1) {
                void* vt2 = esi->vptr;
                void (*fn2)(Inner*) = *(void (**)(Inner*))((char*)vt2 + 8);
                fn2(esi);
            }
        }
    }
}
