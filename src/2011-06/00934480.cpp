// from server: 55% by atomic.potato
struct S_func_00934480
{
    char pad0[0x4594];
    int f(void *);
};

extern "C" int (__cdecl *sub_004cef30)(void *, void *);

int S_func_00934480::f(void *p)
{
    return sub_004cef30((char *)this + 0x4594, p);
}
