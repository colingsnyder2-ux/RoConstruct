// from server: 48% by atomic.potato
extern "C" void RBX_Reflection_Setter(void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *value)
{
    int v = *(int *)value;
    if (v != *(int *)((char *)this + 0xa4))
    {
        *(int *)((char *)this + 0xa4) = v;
        RBX_Reflection_Setter((void *)0xc05fd0, (void *)0x40c470);
    }
    return 0;
}
