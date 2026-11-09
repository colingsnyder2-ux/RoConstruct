// from server: 48% by atomic.potato
struct S {
    void f(float* out, const float* a, const float* b);
};

void S::f(float* out, const float* a, const float* b)
{
    out[0] = b[0];
    out[1] = b[1];
    out[2] = b[2];
    out[3] = -(a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}
