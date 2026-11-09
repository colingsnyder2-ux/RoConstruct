// from server: 64% by atomic.potato
extern "C" void *GetObject(void *);
extern "C" void ReleaseObject(void *, int);

struct S
{
    void f();
};

void S::f()
{
    void *p = GetObject(this);
    while (p != 0)
    {
        ReleaseObject(p, 0);
        p = GetObject(this);
    }
}
