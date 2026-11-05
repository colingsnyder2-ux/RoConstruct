// from server: 100% by atomic.potato
struct S {
    void f();
};

extern "C" void continuation();

void S::f()
{
    *(int *)this = (int)0x00a3b8ec;
    *(int *)((char *)this + 4) = (int)0x00a3b8e4;
    *(int *)((char *)this + 0x18) = (int)0x00a3b8d8;
    *(int *)((char *)this + 0x1c) = (int)0x00a3b8cc;
    continuation();
}
