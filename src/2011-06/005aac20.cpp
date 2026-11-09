// from server: 37% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int a;
    int (*p)(int *, int *, int *) = (int (*)(int *, int *, int *))*(int (**)(int *, int *, int **))((char *)&a - 8);
    return p(&a, &a, &a);
}
