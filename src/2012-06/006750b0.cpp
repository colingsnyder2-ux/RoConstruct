// from server: 16% by atomic.potato
struct T
{
    void operator()(void *, void *);
};

struct S
{
    char data[12];
    void f(void *, void *);
};

void T::operator()(void *, void *)
{
}

void S::f(void *a, void *b)
{
    T *p = (T *)((char *)this + 12);
    p->operator()(a, b);
}
