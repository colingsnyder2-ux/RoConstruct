// from server: 100% by atomic.potato
struct S
{
    char padding[0x24];
    int *field;
    int f();
};

int S::f()
{
    int value = field[7];
    if (value)
        return value - 8;
    return 0;
}
