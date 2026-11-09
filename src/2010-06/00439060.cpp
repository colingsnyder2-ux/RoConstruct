// from server: 84% by atomic.potato
struct S
{
    float value;
    unsigned short type;
    int f(S *a, S *b);
};

int S::f(S *a, S *b)
{
    if (a->value == b->value && a->type == b->type)
        return 1;
    return 0;
}
