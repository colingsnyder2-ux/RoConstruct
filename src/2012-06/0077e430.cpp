// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x00bb0e24;
    *((int *)this + 1) = 0x00bb0e18;
    *((int *)this + 6) = 0x00bb0e0c;
    *((int *)this + 7) = 0x00bb0e00;
}
