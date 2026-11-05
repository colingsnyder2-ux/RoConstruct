// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sscanf_s(const char*, const char*, ...);
extern "C" void __stdcall G1_func_00a404d0();
extern "C" void __stdcall G1_func_00a40998();
extern "C" void __stdcall G1_func_0073f730();

struct S {
    void f();
};

void S::f()
{
    char buf[12];
    void* p = 0;
    G1_func_0073f730();
    void* q = *(void**)buf;
    if (q) {
        char* str;
        if (*(int*)(buf + 0x30) >= 0x10)
            str = *(char**)(buf + 0x1c);
        else
            str = buf + 0x1c;
        int val = 0;
        sscanf_s(str, "0x%x", &val);
        void* g = *(void**)0xcb5afc;
        void** vt = *(void***)g;
        void* arg = (char*)q + 0x1c;
        void (*fn)(void*, int*) = (void (*)(void*, int*))vt[3];
        fn(arg, &val);
    }
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 4), -1) == 1) {
            void** vt = *(void***)q;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(q);
            if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
                void** vt2 = *(void***)q;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(q);
            }
        }
    }
    G1_func_00a404d0();
    void* r = *(void**)(buf + 0x30);
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
            void** vt = *(void***)r;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(r);
        }
    }
}
