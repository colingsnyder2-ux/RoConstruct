// from server: 56% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void G1_func_00537400(void *);

int S::f(void *p)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (p)
        G1_func_00537400(base + ((long)((char *)p - (char *)0x1c)));
    else
        G1_func_00537400(base);
    return 0;
}
