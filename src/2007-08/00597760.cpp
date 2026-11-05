// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

struct Func {
    void* pad0;
    RefCounted* pad4;
};

struct Item {
    void* vptr;
};

struct StatsItem {
    char pad[0x8];
    Item* item;
};

extern "C" void* __stdcall sub_5976E0(void* out, void* in);
extern "C" void __stdcall sub_541630(void* a, void* b);
extern "C" void* __stdcall sub_77E698(void* a);
extern "C" void __stdcall sub_77E6AC(void* a);

struct S {
    void method(void* a, void* b);
};

void S::method(void* a, void* b) {
    void* local1c;
    void* local20;
    void* local24;
    void* local28;
    void* local2c;
    void* local30;
    void* local34;
    void* local38;
    void* local3c;
    void* local40;
    void* local44;

    sub_5976E0(&local1c, a);

    RefCounted* esi = *(RefCounted**)((char*)&local1c + 4);
    Item* edi = *(Item**)&local1c;

    local40 = edi;
    local44 = esi;

    if (esi) {
        _InterlockedExchangeAdd(&esi->refcount, 1);
    }

    RefCounted* ebp = *(RefCounted**)&local20;
    local44 = 0;

    if (ebp) {
        if (_InterlockedExchangeAdd(&ebp->refcount, -1) == 1) {
            void** vt = (void**)ebp->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(ebp);
            if (_InterlockedExchangeAdd(&ebp->weakrefcount, -1) == 1) {
                void** vt2 = (void**)ebp->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(ebp);
            }
        }
    }

    sub_77E698(b);

    void** vt = (void**)edi->vptr;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vt[2];
    fn(edi, &local20);

    sub_77E6AC(&local20);

    sub_541630(edi, a);

    if (esi) {
        if (_InterlockedExchangeAdd(&esi->refcount, -1) == 1) {
            void** vt2 = (void**)esi->vptr;
            void (*fn2)(void*) = (void (*)(void*))vt2[1];
            fn2(esi);
            if (_InterlockedExchangeAdd(&esi->weakrefcount, -1) == 1) {
                void** vt3 = (void**)esi->vptr;
                void (*fn3)(void*) = (void (*)(void*))vt3[2];
                fn3(esi);
            }
        }
    }
}
