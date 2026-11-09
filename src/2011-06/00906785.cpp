// from server: 56% by atomic.potato
extern "C" float __cdecl helper_80ba8c(float);

struct S {
    int a;
    int b;
    int c;
    float d;
};

void __stdcall func_00906785(S* src, S* dst, float* out) {
    if (dst) {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
    }
    if (out) {
        *out = helper_80ba8c(src->d) * 2.0f;
    }
}
