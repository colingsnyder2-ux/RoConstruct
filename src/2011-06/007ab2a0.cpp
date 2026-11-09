// from server: 100% by atomic.potato
struct S
{
    int f();
    int padding[5];
    int value;
};

int S::f()
{
    return value == 13 || value == 271;
}
