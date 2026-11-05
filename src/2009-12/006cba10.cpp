// from server: 48% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int value = *(int *)((char *)this + 0x168);
    if (value)
        return value;
    return 0;
}
