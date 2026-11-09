// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long refCount1;
    volatile long refCount2;
};

struct FactoryProduct {
    void registerAll();
};

extern void __cdecl sub_5F7040(void*);
extern void __cdecl sub_5F70C0(void*);
extern void __cdecl sub_5F7140(void*);
extern void __cdecl sub_5F71C0(void*);
extern void __cdecl sub_5F7240(void*);
extern void __cdecl sub_5F72C0(void*);
extern void __cdecl sub_5F7340(void*);
extern void __cdecl sub_5F73C0(void*);
extern void __cdecl sub_5917B0(void*);

static void releaseRef(RefCounted* p) {
    if (p) {
        if (_InterlockedExchangeAdd(&p->refCount1, -1) == 1) {
            void** vt = p->vptr;
            void (__stdcall *fn)(RefCounted*) = (void (__stdcall *)(RefCounted*))vt[1];
            fn(p);
            if (_InterlockedExchangeAdd(&p->refCount2, -1) == 1) {
                void** vt2 = p->vptr;
                void (__stdcall *fn2)(RefCounted*) = (void (__stdcall *)(RefCounted*))vt2[2];
                fn2(p);
            }
        }
    }
}

void FactoryProduct::registerAll() {
    RefCounted* p;
    sub_5F7040(&p);
    releaseRef(p);
    sub_5F70C0(&p);
    releaseRef(p);
    sub_5F7140(&p);
    releaseRef(p);
    sub_5F71C0(&p);
    releaseRef(p);
    sub_5F7240(&p);
    releaseRef(p);
    sub_5F72C0(&p);
    releaseRef(p);
    sub_5F7340(&p);
    releaseRef(p);
    sub_5F73C0(&p);
    releaseRef(p);
    sub_5917B0(&p);
    releaseRef(p);
}
