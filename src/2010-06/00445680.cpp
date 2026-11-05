// from server: 29% by atomic.potato
extern "C" void CopyString(void *, const void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    void *p = b;
    if (p)
        p = (char *)p - 0x1c;
    CopyString(a, (char *)this + 8 + (int)p);
}
