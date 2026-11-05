// from server: 77% by tester
struct S {
    void f(float* out);
};

extern float g_val;
extern float g_a;
extern float g_b;
extern float g_c;
extern unsigned int g_init;

void S::f(float* out) {
    if (!(g_init & 1)) {
        g_init |= 1;
        g_a = g_val;
        g_b = g_val;
        g_c = g_val;
    }
    out[0] = g_a;
    out[1] = g_b;
    out[2] = g_c;
}
