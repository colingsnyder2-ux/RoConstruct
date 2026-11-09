// from server: 16% by atomic.potato
struct S
{
    int f(void *, void *);
};

struct T
{
    char pad[0x20];
    S *p;

    int f(void *, void *);
};

int S::f(void *, void *)
{
    return 0;
}

int T::f(void *, void *)
{
    return 0;
}
