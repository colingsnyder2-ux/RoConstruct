// from server: 54% by atomic.potato
struct S
{
    int f(void *);
    int *a;
    int *b;
    int c;
};

int S::f(void *p)
{
    int *x = p ? (int *)((char *)p - 28) : 0;
    int *y = (int *)((char *)x + 312);
    int z = y[this->c];
    return ((int (__thiscall *)(int *, int *, int *))this->a)(x, (int *)((char *)this->b + x[0] + 312), (int *)((char *)x + z));
}
