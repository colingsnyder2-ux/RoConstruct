// from server: 38% by atomic.potato
struct S {
    void f(float* out, const float* a, const float* b);
};

void S::f(float* out, const float* a, const float* b)
{
    out[0] = a[0] * b[0] + a[1] * b[4];
    out[1] = a[0] * b[1] + a[1] * b[5];
}
