// from server: 71% by atomic.potato
struct S_func_004a0560
{
    int f(void *p);
};

int S_func_004a0560::f(void *p)
{
    if (*(int *)((char *)this + 0x18) == 0)
        return (int)0x80040213;

    int *obj = *(int **)((char *)this + 0x18);
    int *vtbl = *(int **)obj;
    int (__stdcall *fn)(void *, void *) = *(int (__stdcall **)(void *, void *))(vtbl + 3);

    int result = fn(obj, p);
    if (result < 0)
        return result;

    unsigned int *out = (unsigned int *)p;
    unsigned int lo = *(unsigned int *)((char *)this + 0x20);
    unsigned int hi = *(unsigned int *)((char *)this + 0x24);

    out[0] -= lo;
    out[1] = out[1] - hi - (out[0] > lo ? 1 : 0);

    return 0;
}
