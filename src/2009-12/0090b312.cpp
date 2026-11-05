// from server: 10% by atomic.potato
struct S {
    void f(float* out, const float* a, const float* b);
};

void S::f(float* out, const float* a, const float* b)
{
    float a0 = a[0];
    float a1 = a[1];
    float b0 = b[0];
    float b1 = b[1];
    float b2 = b[2];
    float b3 = b[3];
    out[0] = a0 * b0 + a1 * b2;
    out[1] = a0 * b1 + a1 * b3;
}
