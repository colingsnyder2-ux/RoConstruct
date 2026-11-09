// from server: 100% by atomic.potato
struct S {
    int value;
    int f(const S* a, const S* b);
};

int S::f(const S* a, const S* b)
{
    return a->value == b->value;
}
