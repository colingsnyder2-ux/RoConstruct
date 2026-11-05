// from server: 43% by atomic.potato
extern "C" void G1_func_0069f5f0(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *q = *(void **)((char *)this + 0x2c);
    if (p)
        q = (char *)q + (long)p - 0x1c;
    G1_func_0069f5f0(q);
}
