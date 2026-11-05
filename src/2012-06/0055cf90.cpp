// from server: 60% by atomic.potato
struct EventDesc
{
    int f(int);
};

extern "C" void __stdcall G1_func_0055c2d0(void *);

int EventDesc::f(int value)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (value)
        G1_func_0055c2d0(base + value - 0x1c);
    else
        G1_func_0055c2d0(base);
    return 0;
}
