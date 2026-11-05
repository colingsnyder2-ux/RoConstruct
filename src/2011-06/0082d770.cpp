// from server: 100% by atomic.potato
struct S
{
    void g(void*);
    void f(void*, int);
};

void S::f(void* p, int n)
{
    if (p)
    {
        int i = 0;
        while (i < n)
        {
            g(*((void**)p + i));
            ++i;
        }
    }
}
