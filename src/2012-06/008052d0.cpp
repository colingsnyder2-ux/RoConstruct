// from server: 63% by atomic.potato
extern "C" void G1_func_008040b0(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (p)
        G1_func_008040b0(base + ((long)p - 0x1c));
    else
        G1_func_008040b0(base);
}
