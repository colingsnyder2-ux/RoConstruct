// from server: 100% by tajop
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0xba77ac;
    *(int *)((char *)this + 4) = 0xba77a4;
    *(int *)((char *)this + 0x18) = 0xba7798;
    *(int *)((char *)this + 0x1c) = 0xba778c;
    *(int *)((char *)this + 0x80) = 0xba777c;
    *(int *)((char *)this + 0x84) = 0xba7750;
    extern void g();
    g();
}
