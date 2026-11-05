// from server: 41% by atomic.potato
struct S
{
    void g(float, float);
    void f(float, float);
};

void S::f(float a, float b)
{
    float v[2];
    v[0] = a;
    v[1] = b;
    g(v[0], v[1]);
}
