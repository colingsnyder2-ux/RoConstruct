// from server: 81% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0x00a97a0c;
    *((int *)this + 1) = 0x00a979e4;
}
