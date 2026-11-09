// from server: 56% by atomic.potato
extern "C" float __cdecl helper_7a93d2(float);

struct S {
    void f(int* src, int* dst, float* out);
};

void S::f(int* src, int* dst, float* out) {
    if (dst) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    if (out) {
        *out = helper_7a93d2(*(float*)((char*)src + 12)) * 2.0f;
    }
}
