// from server: 76% by atomic.potato
struct S
{
    void f(int value);
};

void S::f(int value)
{
    if (*(int *)((char *)this + 0xbc) != value)
    {
        *(int *)((char *)this + 0xbc) = value;
        *(int *)0x40c080 = 0xb95ad8;
    }
}
