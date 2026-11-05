// from server: 33% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*(int *)this >= 0x3d09000)
        return 0x400;
    return 0x200;
}
