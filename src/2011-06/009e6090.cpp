// from server: 45% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    volatile unsigned char *p = (volatile unsigned char *)0x30a3fee0;
    volatile unsigned char *q = (volatile unsigned char *)0;
    unsigned long v = 0;
    *p += (unsigned char)v;
    *q = (unsigned char)v;
    __debugbreak();
    *(volatile unsigned char *)0 = (unsigned char)v;
}
