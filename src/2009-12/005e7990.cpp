// from server: 55% by atomic.potato
struct S
{
    struct V
    {
        float value[13];
    };

    int __stdcall f(V **a, V **b);
};

int __stdcall S::f(V **a, V **b)
{
    return (*b)->value[12] > (*a)->value[12];
}
