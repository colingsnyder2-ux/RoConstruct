// from server: 70% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    if (value != *(int *)((char *)this + 0x1d4))
    {
        *(int *)((char *)this + 0x1d4) = value;
        return 0xb97798;
    }
    return 0;
}
