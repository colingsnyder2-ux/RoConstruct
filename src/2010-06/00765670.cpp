// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*((int *)this) == 10 && *((int *)this + 2) == 27)
        return 1;
    return 0;
}
