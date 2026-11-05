// from server: 100% by atomic.potato
struct S
{
    int f();
    char padding[640];
    int value;
};

int S::f()
{
    return value == 1;
}
