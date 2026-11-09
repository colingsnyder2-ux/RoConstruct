// from server: 53% by atomic.potato
struct S
{
    virtual void f(void *, void *);
};

void S::f(void *a, void *b)
{
    ((void (**)(void *, void *))*(void **)((char *)this + 8))[3](
        (char *)this + 8, b);
}
