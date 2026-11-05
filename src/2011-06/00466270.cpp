// from server: 65% by atomic.potato
typedef int (*Callback)(int, int, int, int);

struct S
{
    void f();
};

void S::f()
{
    Callback p = *(Callback *)((char *)this + 0);
    int a = *(int *)((char *)this + 4);
    int b = *(int *)((char *)this + 8);
    int c = *(int *)((char *)this + 12);
    int d = *(int *)((char *)this + 16);
    p(a, b, c, d);
}
