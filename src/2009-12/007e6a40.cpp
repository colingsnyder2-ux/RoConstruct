// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct Inner {
    void* vptr;
    void method1();
    void method2();
};

struct Obj {
    char pad0[0xc];
    void* cs;
    char pad1[0x14];
    char sub[0x18];
    char pad2[0x4];
    void* ptr;
    void release();
    void func(void*);
};

void __stdcall helper1(void*, void*);

void Obj::func(void* arg) {
    void* local = 0;
    EnterCriticalSection(&cs);
    local = cs;
    helper1(&sub, &local);
    release();
    LeaveCriticalSection(&cs);
    Inner* p = (Inner*)ptr;
    if (p) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            p->method1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                p->method2();
            }
        }
    }
}
