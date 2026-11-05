// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl G1_func_005980d0();

void S::f()
{
    *(int *)this = 0xA9587C;
    *(int *)((char *)this + 4) = 0xA95874;
    *(int *)((char *)this + 0x18) = 0xA95868;
    *(int *)((char *)this + 0x1C) = 0xA9585C;
    G1_func_005980d0();
}
