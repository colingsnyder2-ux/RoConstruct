// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" void G1_func_0076b2c0();

int S::f()
{
    G1_func_0076b2c0();
    return (short)*(short *)((*(int *)((char *)this + 0x94)) + 0xaa);
}
