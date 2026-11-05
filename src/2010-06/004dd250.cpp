// from server: 100% by atomic.potato
struct S
{
    void f(int value);
};

void S::f(int value)
{
    *(int *)((char *)this + 8) += value * 8;
}
