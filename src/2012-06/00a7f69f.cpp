// from server: 71% by atomic.potato
struct S {
    void f(float* out, float* a, float* b);
};

void S::f(float* out, float* a, float* b) {
    out[0] = a[0x10/4] * b[1] + a[0] * b[0] + a[0x30/4];
    out[1] = a[1] * b[0] + a[0x14/4] * b[1] + a[0x34/4];
    out[2] = a[2] * b[0] + a[0x18/4] * b[1] + a[0x38/4];
    out[3] = a[3] * b[0] + a[0x1c/4] * b[1] + a[0x3c/4];
}
