// from server: 53% by atomic.potato
struct S
{
    void f(int a, int b, int c, int d);
};

void S::f(int a, int b, int c, int d)
{
    *(int *)((char *)this + 4) = a;
    *(int *)((char *)this + 8) = c;
    *(int *)((char *)this + 12) = *(int *)b;
    *(int *)((char *)this + 16) = *(int *)d;
    *(int *)this = 0xabd0cc;
}
