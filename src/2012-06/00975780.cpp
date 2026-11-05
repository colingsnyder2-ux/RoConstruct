// from server: 81% by atomic.potato
struct S
{
    char padding[216];
    double value;
};

int f(S *a, S *b)
{
    return b->value < a->value ? 1 : 0;
}
