// from server: 38% by atomic.potato
struct S
{
    void f(float, float, float);
};

void S::f(float a, float b, float c)
{
    f(c, b, a);
}
