// from server: 5% by atomic.potato
struct S {
    int f();
    int value;
};

int S::f()
{
    return value;
}
