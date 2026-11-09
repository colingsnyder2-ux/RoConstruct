// from server: 100% by atomic.potato
struct S
{
};

extern "C" void __cdecl G1_func_0074b700(int, void *, int);

void __cdecl f(int a, void *p, int value)
{
    if (value != 4)
    {
        G1_func_0074b700(a, p, value);
        return;
    }

    *(unsigned long *)p = 0x00b58460;
    *((unsigned char *)p + 4) = 0;
    *((unsigned char *)p + 5) = 0;
}
