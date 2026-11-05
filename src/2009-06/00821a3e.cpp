// from server: 19% by atomic.potato
struct S {
    void f(float* a, float* b, float* out);
};

void S::f(float* a, float* b, float* out) {
    float x = a[0];
    float y = a[1];
    out[0] = x * b[0] + y * b[4];
    out[1] = x * b[1] + y * b[5];
}
