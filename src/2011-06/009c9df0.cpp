// from server: 18% by atomic.potato
struct S
{
    int f(int);
    void g(int *);
};

void S::g(int *p)
{
}

int S::f(int value)
{
    g(&value);
    return 0;
}
