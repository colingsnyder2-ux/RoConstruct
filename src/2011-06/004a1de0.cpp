// from server: 85% by atomic.potato
extern "C" void sub_0080a058(void *);

struct CEnumMediaTypes
{
    int f(int);
};

int CEnumMediaTypes::f(int flags)
{
    void *p = *(void **)((char *)this + 8);
    p = (char *)p + 12;

    *(int *)this = 0x00a76848;

    void **vtable = *(void ***)p;
    ((void (__thiscall *)(void *))vtable[2])(p);

    if (flags & 1)
        sub_0080a058(this);

    return (int)this;
}
