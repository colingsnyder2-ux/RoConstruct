// from server: 49% by atomic.potato
struct S
{
    char pad0[8];
    void* (__thiscall *fn)(void*);
    char padC[4];
    void* fieldC;
    void* construct(void* dst, void* src);
};

void* S::construct(void* dst, void* src)
{
    void* p = src;
    if (p != 0)
        p = (char*)p - 0x1c;
    else
        p = 0;
    void* arg = (char*)fieldC + (int)p;
    void* result = fn(arg);
    extern void __stdcall string_copy_ctor(void*, void*);
    string_copy_ctor(dst, result);
    return dst;
}
