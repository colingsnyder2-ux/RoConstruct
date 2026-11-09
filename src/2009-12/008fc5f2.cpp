// from server: 22% by atomic.potato
struct S {
    void f(float* out, const float* a, const float* b);
};

void S::f(float* out, const float* a, const float* b)
{
    float x = a[0];
    float y = a[1];
    out[0] = x * b[0] + y * b[4];
    out[1] = x * b[1] + y * b[5];
}
