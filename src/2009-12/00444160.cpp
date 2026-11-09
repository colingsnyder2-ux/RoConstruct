// from server: 75% by atomic.potato
struct S
{
    void f(int *p);
};

void S::f(int *p)
{
    *p = *(int *)((char *)this + 0x4a);
}
