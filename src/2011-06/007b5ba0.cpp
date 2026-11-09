// from server: 85% by atomic.potato
struct S
{
    S* f(int, int);
};

S* S::f(int a, int b)
{
    this->f(a, b);
    return this;
}
