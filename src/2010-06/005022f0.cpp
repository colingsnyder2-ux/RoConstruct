// from server: 95% by atomic.potato
struct S_func_005022f0
{
    int __cdecl f(unsigned short *a, unsigned short *b);
};

int __cdecl S_func_005022f0::f(unsigned short *a, unsigned short *b)
{
    unsigned short x = *a;
    unsigned short y = *(unsigned short *)(*(int *)*(int *)(*(int *)b + 8) + 0x20);
    if (x < y)
        return -1;
    return x != y;
}
