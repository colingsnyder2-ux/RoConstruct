// from server: 59% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    volatile int value = 0;
    volatile int result;
    result = value;
    return result;
}
