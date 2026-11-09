// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct Holder {
    Inner* ptr;
};

struct Src {
    char pad[0x18];
    Holder holder;
};

struct Out {
    Inner* ptr;
};

extern "C" void* __cdecl sub_41E0F0(void*);
extern "C" void __cdecl sub_4621E0(Out*, void*);

void __cdecl target(Src* src, Out* out)
{
    Inner* esi = 0;
    int ebx;

    if (src != 0) {
        void* tmp;
        sub_41E0F0(&src->holder);
        sub_4621E0(out, &tmp);
        esi = out->ptr;
        ebx = 3;
    } else {
        esi = 0;
        out->ptr = 0;
        ebx = 4;
    }

    if (out->ptr != 0) {
        _InterlockedExchangeAdd(&out->ptr->refcount, 1);
    }

    ebx |= 8;
    if (ebx & 4) {
        ebx &= ~4;
        if (esi != 0) {
            if (_InterlockedExchangeAdd(&esi->refcount, -1) == 1) {
                void (*f)(Inner*) = *(void (**)(Inner*))((char*)esi->vptr + 4);
                f(esi);
                if (_InterlockedExchangeAdd(&esi->weakrefcount, -1) == 1) {
                    void (*g)(Inner*) = *(void (**)(Inner*))((char*)esi->vptr + 8);
                    g(esi);
                }
            }
        }
    }

    if (ebx & 2) {
        Inner* esi2 = out->ptr;
        ebx &= ~2;
        if (esi2 != 0) {
            if (_InterlockedExchangeAdd(&esi2->refcount, -1) == 1) {
                void (*f)(Inner*) = *(void (**)(Inner*))((char*)esi2->vptr + 4);
                f(esi2);
                if (_InterlockedExchangeAdd(&esi2->weakrefcount, -1) == 1) {
                    void (*g)(Inner*) = *(void (**)(Inner*))((char*)esi2->vptr + 8);
                    g(esi2);
                }
            }
        }
    }

    if (ebx & 1) {
        Inner* esi3 = out->ptr;
        ebx &= ~1;
        if (esi3 != 0) {
            if (_InterlockedExchangeAdd(&esi3->refcount, -1) == 1) {
                void (*f)(Inner*) = *(void (**)(Inner*))((char*)esi3->vptr + 4);
                f(esi3);
                if (_InterlockedExchangeAdd(&esi3->weakrefcount, -1) == 1) {
                    void (*g)(Inner*) = *(void (**)(Inner*))((char*)esi3->vptr + 8);
                    g(esi3);
                }
            }
        }
    }
}
