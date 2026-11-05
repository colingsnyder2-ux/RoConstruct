// from server: 56% by atomic.potato
extern "C" void sub_7851a0(void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *base = *(char **)((char *)this + 0x2c);
    if (p)
        sub_7851a0(base + *(int *)p - 0x1c);
    else
        sub_7851a0(base);
}
