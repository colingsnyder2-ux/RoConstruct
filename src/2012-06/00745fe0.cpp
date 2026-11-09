// from server: 50% by atomic.potato
struct S
{
    float value;
    unsigned short unit;

    void f(S* a, const S* b);
};

void S::f(S* a, const S* b)
{
    float v = value;
    unsigned short u = unit;
    u = (unsigned short)(u - b->unit);
    v -= b->value;
    a->value = v;
    a->unit = u;
}
