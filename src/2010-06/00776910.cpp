// from server: 52% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0xa0) = 0;
}
