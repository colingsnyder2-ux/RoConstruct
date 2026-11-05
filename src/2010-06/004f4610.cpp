// from server: 0% by colin
// from server: 20% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    volatile int value = 0;
    return value;
}
