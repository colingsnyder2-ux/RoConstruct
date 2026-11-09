// from server: 50% by atomic.potato
struct S
{
    int (*function)(void *, unsigned int);
    void *value;
    unsigned int offset;
    void *context;
    int f(void *, unsigned int);
};

int S::f(void *a, unsigned int b)
{
    return function((char *)value + offset, b);
}
