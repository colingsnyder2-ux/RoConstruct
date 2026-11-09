// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int value = *(int *)((char *)this + 0x16c);
    if (value == 1 || value == 2)
        return 1;
    return 0;
}
