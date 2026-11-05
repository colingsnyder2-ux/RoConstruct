// from server: 50% by atomic.potato
struct S {
    void f(float *out);
};

extern "C" void __cdecl helper_6b1320(float *out);

void S::f(float *out) {
    float tmp[4];
    helper_6b1320(tmp);
    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
}
