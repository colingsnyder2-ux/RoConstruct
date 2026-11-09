// from server: 48% by atomic.potato
struct S {
    void f(float* a, float* b, float* c);
};

void S::f(float* a, float* b, float* c)
{
    a[0] = c[0];
    a[1] = c[1];
    a[2] = c[2];
    a[3] = -(b[0] * c[0] + b[1] * c[1] + b[2] * c[2]);
}
