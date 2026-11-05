// from server: 100% by atomic.potato
struct S
{
    void f(int*, int);
    void g(int);
};

void S::f(int* p, int n)
{
    if (p)
    {
        int i = 0;
        while (i < n)
        {
            g(p[i]);
            ++i;
        }
    }
}
