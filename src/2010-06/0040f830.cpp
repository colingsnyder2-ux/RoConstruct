// from server: 70% by atomic.potato
struct S
{
    int f(int);
    int g(int);
};

int S::g(int value)
{
    return value;
}

int S::f(int value)
{
    if (!g(value))
        return 0;

    int flags = *(int *)((char *)this + 0x20);
    flags = (flags & 0xffcfff7f) | 0x08000000;
    *(int *)((char *)this + 0x20) = flags;
    return 1;
}
