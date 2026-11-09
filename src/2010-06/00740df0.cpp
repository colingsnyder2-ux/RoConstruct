// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* p0;
    void* p4;
    void* p8;
    void* pc;
};

struct Outer {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    char pad10[0x10];
    void* f20;
};

struct S {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    void (__stdcall *fn)(void*, void*, void*);
    void method(void* arg);
};

void S::method(void* arg)
{
    Inner local;
    local.p0 = f8;
    local.p4 = fc;
    if (local.p4) {
        _InterlockedExchangeAdd((volatile long*)((char*)local.p4 + 4), 1);
    }
    Outer* src = (Outer*)arg;
    void* a = f4;
    void* b = f0;
    void* v = *(void**)src;
    void* buf[10];
    buf[0] = 0;
    void* obj = *(void**)v;
    buf[0] = obj;
    if (obj) {
        void* vt = *(void**)v;
        void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))vt;
        fn(0, (char*)buf + 8, (char*)v + 8);
    }
    buf[4] = *(void**)((char*)v + 0x20);
    void* vt2 = *(void**)src;
    void (*fn2)(void*) = *(void (**)(void*))vt2;
    fn2(vt2);
}
