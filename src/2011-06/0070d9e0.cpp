// from server: 36% by atomic.potato
extern "C" void __cdecl fn_0053bcc0();
extern "C" void __cdecl fn_0053bd30();
extern "C" void __cdecl fn_00a404c4();
extern "C" void __cdecl fn_00a404d0();
extern "C" void __cdecl fn_00a40954();
extern "C" void __cdecl fn_00c3316c();
extern "C" void __cdecl fn_00a789c4();
extern "C" void __cdecl fn_00a78984();
extern "C" void __cdecl fn_00a7897c();

struct Alloc {
    void* (*alloc)(int);
    void (*free)(void*);
};

struct Arr {
    char* data;
    int size;
    int cap;
    Alloc* alloc;
    void resize(int n);
};

void Arr::resize(int n)
{
    char* old = data;
    int oldsize = size;
    char* nd = (char*)alloc->alloc(n * 8);
    data = nd;
    if (!nd) {
        fn_0053bcc0();
        if (*(int*)0xc3316c) {
            fn_00a789c4();
            fn_00a404c4();
            fn_00c3316c();
            fn_00a404d0();
            fn_00a40954();
        }
        fn_0053bd30();
    }
    int cnt = size < n ? size : n;
    char* src = old;
    char* dst = data;
    char* end = data + cnt * 8;
    while (dst < end) {
        if (dst) {
            *(int*)dst = *(int*)src;
            *(int*)(dst + 4) = *(int*)(src + 4);
        }
        dst += 8;
        src += 8;
    }
    alloc->free(old);
}
