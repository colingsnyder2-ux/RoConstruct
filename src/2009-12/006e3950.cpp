// from server: 11% by atomic.potato
struct S
{
    S& f(float value);
};

S& S::f(float value)
{
    return *this;
}
