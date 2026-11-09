// from server: 100% by tester
struct S {
    void f(float* out);
};

extern float g_val;

void S::f(float* out)
{
    out[0] = 0.0f;
    out[1] = g_val;
}
