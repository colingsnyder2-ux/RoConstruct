// from server: 81% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0;
    *((int *)this + 1) = 0;
    *((int *)this + 2) = -1;
}
