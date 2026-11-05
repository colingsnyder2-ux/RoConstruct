// from server: 74% by atomic.potato
struct S
{
};

double __cdecl f(void *p)
{
    struct T
    {
        double *(*fn)(T *);
    };
    T *q = *reinterpret_cast<T **>(p);
    return *q->fn(q);
}
