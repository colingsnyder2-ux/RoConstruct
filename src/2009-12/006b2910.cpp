// from server: 46% by atomic.potato
struct S
{
    float value;
    unsigned short part;
    void f(S* out, const S* other);
};

void S::f(S* out, const S* other)
{
    out->value = value - other->value;
    out->part = (unsigned short)(part - other->part);
}
