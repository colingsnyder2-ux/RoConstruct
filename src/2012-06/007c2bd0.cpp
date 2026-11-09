// from server: 70% by atomic.potato
typedef unsigned char byte;

extern byte g_00e31abe;

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    if (g_00e31abe)
        return;

    void *p = *(void **)((char *)this + 0x84);
    void *q = (char *)p + *(unsigned long *)p + (unsigned long)this + 0x84;
    ((void (__thiscall *)(void *, void *))0x684900)(q, arg);
}
