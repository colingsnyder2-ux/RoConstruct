// from server: 19% by atomic.potato
struct S {
    int f();
    int value[9];
};

int S::f()
{
    return value[8] < 30 ? 1 : 2;
}
