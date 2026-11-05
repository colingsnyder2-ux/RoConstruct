// from server: 77% by atomic.potato
struct S
{
    int a[65];
    int b[1];
    void f(void *);
};

void S::f(void *p)
{
    int i = a[64];
    int *q = *(int **)((char *)this + 0xfc);
    ((int *)p)[0] = (int)(q + i);
    ((int *)p)[1] = q[i];
}
