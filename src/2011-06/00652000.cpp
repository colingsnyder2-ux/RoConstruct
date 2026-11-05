// from server: 66% by atomic.potato
struct S
{
    int value;
    int f(int index);
};

int S::f(int index)
{
    if (index < 0 || index > 2)
        return 0;
    return (value & (1 << index)) != 0;
}
