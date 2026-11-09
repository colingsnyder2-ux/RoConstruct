// from server: 36% by atomic.potato
struct S_func_007ecec0 {
    void f(float a, float b);
};

extern "C" void __stdcall sub_007ecda0(float* out, float a, float b);

void S_func_007ecec0::f(float a, float b)
{
    float tmp[4];
    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    tmp[2] = 0.0f;
    tmp[3] = 0.0f;
    sub_007ecda0(tmp, a, b);
}
