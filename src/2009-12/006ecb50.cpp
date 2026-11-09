// from server: 100% by atomic.potato
struct S
{
    int f();
    int a[46];
};

int S::f()
{
    if (a[46] > 0)
        return *(int*)a[45];
    return 0;
}
