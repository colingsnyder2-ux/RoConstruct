// from server: 76% by atomic.potato
struct S_func_00475490
{
    virtual void f0();
    virtual void f1();
    unsigned char f(void *);
};

unsigned char S_func_00475490::f(void *p)
{
    void *v = *(void **)((char *)this + 0xf0);

    if (v)
        ((void (__thiscall *)(char *))(*(unsigned long *)(*(unsigned long *)v + 4)))((char *)v);

    unsigned char same = (v == p);

    if (v)
        ((void (__thiscall *)(char *))(*(unsigned long *)(*(unsigned long *)v + 8)))((char *)v);

    return same;
}
