// from server: 70% by atomic.potato
struct S
{
    int f();
    int g();
};

int S::g()
{
    return 0;
}

int S::f()
{
    g();
    return (short)*(short *)((char *)*(int *)((char *)this + 0x94) + 0xA8);
}
