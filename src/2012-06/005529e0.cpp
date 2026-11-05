// from server: 63% by atomic.potato
extern "C" void Target(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (p)
        Target(base + (((char *)p - (char *)0) - 0x1c));
    else
        Target(base);
}
