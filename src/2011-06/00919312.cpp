// from server: 15% by atomic.potato
struct S_func_00919312 {
    void* f(void* a, void* b, void* c);
};

void* S_func_00919312::f(void* a, void* b, void* c)
{
    float* src = (float*)a;
    float* m = (float*)b;
    float* dst = (float*)c;

    float x = src[0];
    float y = src[1];

    dst[0] = x * m[0] + y * m[4];
    dst[1] = x * m[1] + y * m[5];

    return c;
}
