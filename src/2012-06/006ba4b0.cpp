// from server: 65% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();
extern void G1_func_006b9f30(void *, unsigned long);

struct S
{
    int value_24;
    int value_38;
    void f(int, unsigned char);
};

void S::f(int value, unsigned char flag)
{
    void *p;
    if ((unsigned int)value_38 < 0x10)
        p = (void *)(value_24 + 0x24);
    else
        p = (void *)value_24;

    if (flag == 0)
    {
        G1_func_006b9f30(p, (unsigned long)value);
        G1_func_006b9f30(p, GetLastError());
    }
}
