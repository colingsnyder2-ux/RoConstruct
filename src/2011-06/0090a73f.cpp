// from server: 13% by atomic.potato
struct S {
    void f(float* out, const float* a, const float* b);
};

void S::f(float* out, const float* a, const float* b)
{
    float x = a[0];
    float y = a[1];
    float r0 = x * b[0] + y * b[4];
    float r1 = x * b[1] + y * b[5];
    out[0] = r0;
    out[1] = r1;
}
