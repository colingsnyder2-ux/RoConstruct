// from server: 30% by atomic.potato
struct S
{
    void f(int, int);
    void g(int *, int *);
};

void S::f(int a, int b)
{
    g(&a, &b);
}
