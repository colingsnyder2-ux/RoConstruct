// from server: 70% by atomic.potato
extern "C" void __cdecl sym(void *);

struct S_func_0052ba00
{
    char pad0[20];
    int m14;
    char pad18[16];
    int m28;
    S_func_0052ba00 *f(void *);
};

S_func_0052ba00 *S_func_0052ba00::f(void *arg)
{
    S_func_0052ba00 *result;
    result = this;
    sym(arg);
    m28 = 0x00a00920;
    *(int *)this = 0x00a1ed68;
    m14 = 0x00a1ed60;
    m28 = 0x00a1ed50;
    return result;
}
