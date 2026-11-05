// from server: 52% by atomic.potato
struct S {
    int f(int);
};

struct T {
    int g(int *);
};

int S::f(int a)
{
    int v;
    T *p = (T *)(a + 4);
    v = *(int *)p->g(0);
    return ((T *)this)->g(&v);
}
