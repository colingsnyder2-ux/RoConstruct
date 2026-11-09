// from server: 14% by atomic.potato
struct S {
    void* f(void* a, void* b, void* c);
};

void* S::f(void* a, void* b, void* c) {
    float* src = (float*)b;
    float* dst = (float*)c;
    float* out = (float*)a;

    float x = src[0];
    float y = src[1];
    float z = src[2];
    float w = src[3];

    float r0 = x * dst[0] + y * dst[1];
    float r1 = z * dst[2] + w * dst[3];

    out[0] = r0;
    out[1] = r1;

    return a;
}
