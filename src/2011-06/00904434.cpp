// from server: 35% by atomic.potato
struct S {
    void f(float* out, float* a, float* b, float* c, float* d, float t);
};

void S::f(float* out, float* a, float* b, float* c, float* d, float t)
{
    float x = t * t;
    float y = t * t;
    float z = t;
    float u = x + y;
    float v = z * 0.0f;
    float w = u - v + 0.0f;
    float p = t + t;
    float q = p - t;
    float r = q + t;
    out[0] = w * a[0] + r * b[0] + t * c[0] + z * d[0];
    out[1] = w * a[1] + r * b[1] + t * c[1] + z * d[1];
    out[2] = w * a[2] + r * b[2] + t * c[2] + z * d[2];
}
