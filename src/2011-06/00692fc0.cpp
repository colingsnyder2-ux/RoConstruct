// from server: 67% by atomic.potato
struct S
{
    void f(int *, int *);
};

void S::f(int *out, int *value)
{
    int offset = *(int *)((char *)this + 8);
    if (value != 0)
        *out = *(int *)((char *)value + offset - 0x1c);
    else
        *out = *(int *)((char *)this + 8);
}
