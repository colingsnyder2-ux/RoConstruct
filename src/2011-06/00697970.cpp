// from server: 100% by atomic.potato
struct S
{
};

extern void G1_func_00697690(void *, int, int);

void __cdecl f(void *a, int b, int c)
{
    if (c != 4)
    {
        G1_func_00697690(a, b, c);
        return;
    }

    *(unsigned long *)b = 0x00c62a00;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
