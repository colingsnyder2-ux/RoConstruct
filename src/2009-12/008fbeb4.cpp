// from server: 36% by atomic.potato
struct S {
    void f(float* a, float* b, float* out);
};

void S::f(float* a, float* b, float* out) {
    out[0] = a[0] * b[0] + a[1] * b[4];
    out[1] = a[0] * b[1] + a[1] * b[5];
}
