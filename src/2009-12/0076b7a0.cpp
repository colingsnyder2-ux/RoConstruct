// from server: 72% by atomic.potato
struct S
{
    int f();
};

extern "C" void __stdcall G1_func_006f92b0();

int S::f()
{
    if (*(int *)((char *)this + 0x9c) != 0 ||
        *(unsigned char *)((char *)this + 0xa0) != 0)
    {
        G1_func_006f92b0();
    }
    return 0;
}
