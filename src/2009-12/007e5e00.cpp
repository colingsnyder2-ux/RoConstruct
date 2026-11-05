// from server: 81% by atomic.potato
struct S
{
    char pad[184];
    double value;
};

int f(S* a, S* b)
{
    return b->value < a->value;
}
