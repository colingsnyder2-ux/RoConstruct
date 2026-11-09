// from server: 70% by atomic.potato
struct S
{
    int count;
    int* link;
    void f(int* a, int* b);
};

void S::f(int* a, int* b)
{
    int* p = b;
    int* q = (int*)p[0];

    if (q != 0)
    {
        int* r = (int*)p[1];
        r[0] = (int)q;
        q[1] = (int)r;
    }

    --count;
    p[0] = 0;
    p[1] = 0;
    a[0] = (int)q;
}
