// from server: 20% by atomic.potato
struct S {
    int value;
    int f();
};

int S::f()
{
    return value < 30 ? 2 : 1;
}
