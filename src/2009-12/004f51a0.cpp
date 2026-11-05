// from server: 38% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    return *(int *)this == 0x047868c0 ? 1 : 0;
}
