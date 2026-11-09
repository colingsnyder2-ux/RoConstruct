// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vtable;
    long refcount;
};

struct Inner {
    char pad0[4];
    void* ptr;
    char pad1[4];
    char flag0;
    char pad2[3];
    char flag1;
};

struct CLuaHtmlView {
    void* field0;
    RefCounted* field4;
    void* field8;
    Inner inner;
    void construct(void* a, RefCounted* b, void* c, void* d);
};

extern "C" void __cdecl sub_42C9C0(void*);
extern "C" void* __cdecl sub_42C020(void*, void*, void*);
extern "C" void __cdecl sub_49A230(void*);
extern "C" void __cdecl sub_728460(void*);
extern "C" void __cdecl sub_728640(void*, void*);

void CLuaHtmlView::construct(void* a, RefCounted* b, void* c, void* d) {
    field0 = a;
    field4 = b;
    if (b != 0) {
        _InterlockedExchangeAdd(&b->refcount, 1);
    }
    field8 = c;
    inner.ptr = 0;
    inner.flag0 = 0;
    inner.flag1 = 0;

    char local18[8];
    *(void**)(local18 + 0) = (void*)0x42cf10;
    *(void**)(local18 + 4) = c;
    char local28[16];
    sub_42C9C0(local18);
    void* p = (b != 0) ? (void*)((char*)b + 4) : 0;
    void* r = sub_42C020((void*)0x8c1608, p, local28);
    sub_728640(&inner, r);
    sub_728460(local28);
    sub_49A230(local18);

    if (b != 0) {
        if (_InterlockedExchangeAdd(&b->refcount, -1) == 1) {
            void** vt = *(void***)b;
            void (__stdcall *fn1)(RefCounted*) = (void (__stdcall *)(RefCounted*))vt[1];
            fn1(b);
            if (_InterlockedExchangeAdd(&b->refcount, -1) == 1) {
                void (__stdcall *fn2)(RefCounted*) = (void (__stdcall *)(RefCounted*))vt[2];
                fn2(b);
            }
        }
    }
}
