// from server: 48% by atomic.potato
struct Inner;

struct S
{
    char padding[0x1c];
    Inner* inner;
    bool __thiscall f(float, float);
};

struct Inner
{
    virtual float __thiscall get(float) = 0;
};

bool __thiscall S::f(float a, float b)
{
    float x = this->inner->get(a);
    float y = this->inner->get(b);
    return x == y;
}
