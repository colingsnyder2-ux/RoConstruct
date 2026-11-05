// from server: 100% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0xe8) |= 1;
    *(int *)((char *)this + 0xcc) = -1;
    *(int *)((char *)this + 0xd0) = -1;
}
