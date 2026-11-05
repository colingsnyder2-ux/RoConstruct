// from server: 43% by atomic.potato
struct S
{
    void f(float *p);
};

void S::f(float *p)
{
    p[0] = 0.0f;
    p[1] = 0.0f;
    p[2] = 0.0f;
}
