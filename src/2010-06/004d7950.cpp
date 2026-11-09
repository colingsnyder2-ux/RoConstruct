// from server: 71% by atomic.potato
extern "C" void SetDescriptor(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    void *v = *(void **)value;
    if (v != *(void **)((char *)this + 0xa0))
    {
        *(void **)((char *)this + 0xa0) = v;
        SetDescriptor(this, (void *)0xc05ff8);
    }
}
