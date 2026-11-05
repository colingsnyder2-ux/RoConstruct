// from server: 100% by atomic.potato
extern "C" __declspec(dllimport) void* __cdecl __iob_func();
extern "C" __declspec(dllimport) int __cdecl fprintf(void*, const char*, ...);

struct S {
};

void __cdecl f(void* a) {
    char buf[200];
    void* p = *(void**)a;
    ((void (__cdecl*)(void*, char*))*(void**)((char*)p + 0xc))(a, buf);
    fprintf((void*)((char*)__iob_func() + 0x40), (const char*)0x9bea30, buf);
}
