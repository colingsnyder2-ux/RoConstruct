// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    void method1();
    void method2();
};

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
    void Release();
};

struct Sub {
    char pad0[0x1d0];
    void func_004df640(void*);
};

struct Outer {
    char pad0[8];
    Sub* sub;
    RefCounted* ref;
    void func_004df6a0(void*, RefCounted*, int, int, char, int, int, char);
};

void RefCounted::Release()
{
    if (_InterlockedExchangeAdd(&refcount, -1) == 1) {
        void** vt = (void**)vptr;
        ((void (__thiscall*)(RefCounted*))vt[1])(this);
        if (_InterlockedExchangeAdd(&weakrefcount, -1) == 1) {
            void** vt2 = (void**)vptr;
            ((void (__thiscall*)(RefCounted*))vt2[2])(this);
        }
    }
}

extern void __cdecl func_0079b5b0();
extern void __cdecl func_0079a6a0();

void Outer::func_004df6a0(void* a, RefCounted* b, int c, int d, char e, int f, int g, char h)
{
    char buf[0x20];
    *(void**)(buf + 0) = a;
    *(RefCounted**)(buf + 4) = b;
    if (b) {
        _InterlockedExchangeAdd(&b->refcount, 1);
    }
    *(int*)(buf + 8) = c;
    *(int*)(buf + 12) = d;
    *(char*)(buf + 16) = e;
    *(int*)(buf + 20) = f;
    *(int*)(buf + 24) = g;
    *(char*)(buf + 28) = h;
    sub->func_004df640(buf);
    func_0079b5b0();
    func_0079a6a0();
    if (b) {
        b->Release();
    }
}
