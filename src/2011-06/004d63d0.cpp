// from server: 52% by atomic.potato
struct S {
    char pad0[4];
    char pad4[0x14];
    unsigned int len;
};

extern "C" void __cdecl f401610();
extern "C" void* __cdecl f4d3500();
extern "C" void* __cdecl f592e10(void*, void*);
extern "C" void* __cdecl f5a8570(void*, void*);

void* __cdecl f(S* p) {
    char* data;
    if (p->len < 0x10)
        data = (char*)p + 4;
    else
        data = *(char**)((char*)p + 4);

    f401610();
    void* r = f4d3500();
    void* tmp = data;
    void* arg = f592e10(&tmp, &tmp);
    return f5a8570(r, arg);
}
