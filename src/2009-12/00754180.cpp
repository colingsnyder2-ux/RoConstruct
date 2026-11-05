// from server: 76% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *q;
    if (p)
        q = (char *)p - 0x1c;
    else
        q = 0;
    ((void (__thiscall *)(char *, char *))(*(void **)((char *)this + 8)))(
        q + *(int *)((char *)this + 0xc) +
        ((int *)*(void **)(q + 0x98))[
            *(int *)((char *)this + 0x10)],
        q);
}
