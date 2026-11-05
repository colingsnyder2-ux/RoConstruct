// from server: 15% by atomic.potato
struct S {
    void* f(void* a, void* b, void* c);
};

void* S::f(void* a, void* b, void* c) {
    float* src = (float*)a;
    float* mtx = (float*)b;
    float* dst = (float*)c;

    float x = src[0];
    float y = src[1];

    dst[0] = x * mtx[0] + y * mtx[4];
    dst[1] = x * mtx[1] + y * mtx[5];

    return c;
}
