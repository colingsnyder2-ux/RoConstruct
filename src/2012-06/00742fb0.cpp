// from server: 50% by atomic.potato
struct S {
    void f(float* out);
};

extern "C" void __cdecl sub_742F00(float* out);

void S::f(float* out) {
    float tmp[4];
    sub_742F00(tmp);
    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
}
