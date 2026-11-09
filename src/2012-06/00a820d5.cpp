// from server: 36% by atomic.potato
struct S {
    void f(float* a, float* b, float* c);
};

void S::f(float* a, float* b, float* c)
{
    c[0] = a[0] * b[0] + a[1] * b[4];
    c[1] = a[0] * b[1] + a[1] * b[5];
}
