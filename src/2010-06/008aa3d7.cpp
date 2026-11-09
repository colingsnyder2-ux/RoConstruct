// from server: 39% by colin
struct S {
    void f(float* out, const float* a, const float* b, const float* c, float t1, float t2);
};

void S::f(float* out, const float* a, const float* b, const float* c, float t1, float t2)
{
    out[0] = (b[0] - a[0]) * t1 + (c[0] - a[0]) * a[0] + t2;
    out[1] = (b[1] - a[1]) * t1 + (c[1] - a[1]) * t2 + a[1];
}
