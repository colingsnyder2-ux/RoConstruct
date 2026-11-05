// from server: 100% by atomic.potato
struct S {
    void f();
};

extern "C" void G1_func_005980d0();

void S::f()
{
    *(int *)((char *)this + 0x00) = 0x00aa1444;
    *(int *)((char *)this + 0x04) = 0x00aa143c;
    *(int *)((char *)this + 0x18) = 0x00aa1430;
    *(int *)((char *)this + 0x1c) = 0x00aa1424;
    *(int *)((char *)this + 0x90) = 0x00aa141c;
    G1_func_005980d0();
}
