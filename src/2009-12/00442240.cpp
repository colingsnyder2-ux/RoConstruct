// from server: 37% by atomic.potato
struct S
{
    void *f();
    char pad[148];
    void *p;
};

void *S::f()
{
    if (p)
        return p;
    return 0;
}
