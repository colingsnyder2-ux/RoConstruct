// from server: 92% by atomic.potato
struct S {
    int f(S *);
};

struct C {
    void operator()(void *, const void *);
};

int S::f(S *p)
{
    char *dst = (char *)this + 0xf4;
    ((C *)0)->operator()(dst, p);
    *(float *)((char *)p + 0x24) = *(float *)(dst + 0x24);
    *(float *)((char *)p + 0x28) = *(float *)(dst + 0x28);
    *(float *)((char *)p + 0x2c) = *(float *)(dst + 0x2c);
    return (int)p;
}
