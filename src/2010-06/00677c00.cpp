// from server: 36% by atomic.potato
struct S
{
    char pad[208];
    S* next;
    float value;

    void f(float v);
};

void S::f(float v)
{
    if (v != value)
    {
        value = v;
        if (next)
            next->f(v);
    }
}
