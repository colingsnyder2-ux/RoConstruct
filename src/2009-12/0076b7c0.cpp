// from server: 45% by atomic.potato
struct S
{
    int f();
    void g();
    int x[37];
};

void S::g()
{
}

int S::f()
{
    g();
    return (int)(short)x[40];
}
