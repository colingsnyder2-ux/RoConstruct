// from server: 56% by atomic.potato
struct S
{
    typedef void (__thiscall *F)(int, int, int, int);

    void f();
};

void S::f()
{
    F fn = *(F *)*(int **)((char *)this + 4);
    fn(*(int *)((char *)this + 4),
       *(int *)((char *)this + 8),
       *(int *)((char *)this + 0xc),
       *(int *)((char *)this + 0x10));
}
