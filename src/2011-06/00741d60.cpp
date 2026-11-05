// from server: 43% by atomic.potato
struct S
{
    void f(float, float, float, float);
};

void S::f(float a, float b, float c, float d)
{
    S* p = this + 1;
    p->f(d, c, b, a);
}
