// from server: 32% by atomic.potato
struct S
{
    int value;
    S* next;
    int f();
};

int S::f()
{
    while (next != 0)
        ;
    return value - 8;
}
