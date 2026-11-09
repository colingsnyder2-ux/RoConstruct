// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*(int *)this == 10)
    {
        int value = *((int *)this + 2);
        if (value == 13 || value == 271)
            return 1;
    }
    return 0;
}
