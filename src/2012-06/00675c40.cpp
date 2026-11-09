// from server: 16% by atomic.potato
struct S
{
    void (*field10)(S *);
    int f();
};

int S::f()
{
    if (field10 != 0)
    {
        field10(this);
    }
    return 0;
}
