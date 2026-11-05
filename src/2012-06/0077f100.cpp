// from server: 53% by atomic.potato
struct S
{
    void* Get(unsigned int);
    int f(unsigned int);
};

int S::f(unsigned int value)
{
    void* p = Get(value + 4);
    unsigned int v = *(unsigned int*)p;
    return f(v);
}
