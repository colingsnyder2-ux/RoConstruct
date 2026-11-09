// from server: 44% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x68) = 0xA5BEE8;
    *(int *)this = 0xA9A864;
    *(int *)((char *)this + 0x54) = 0xA9A85C;
    *(int *)((char *)this + 0x54) = 0xA5BFDC;
    void **p = *(void ***)((char *)this + 0x58);
    if (p)
        ((void (__thiscall *)(void *))p[4])(p);
}
