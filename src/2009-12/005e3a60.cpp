// from server: 64% by atomic.potato
struct S
{
    int f(void *, void *);
};

void sub_5cac40(S *, void *, void *);

int S::f(void *a, void *b)
{
    sub_5cac40(this, b, a);
    *(unsigned long *)this = 0x009c1730;
    *(float *)((char *)this + 0x5c) = 0.0f;
    return (int)this;
}
