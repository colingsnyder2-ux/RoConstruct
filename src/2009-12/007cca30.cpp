// from server: 67% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    unsigned int v = *((unsigned int *)((char *)p + 8));
    if (v != 8 && v != 0x1b && v != 0x7f)
        return;
    void **q = (void **)((char *)this + 0x44);
    ((void (__thiscall *)(void *))q[0])((char *)this + 0x44);
}
