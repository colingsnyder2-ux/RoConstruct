// from server: 59% by atomic.potato
extern "C" void __stdcall sub_007bd830(float, float *);

struct AdvRunDragger
{
    void f(float);
};

float g_00a7fb98;

void AdvRunDragger::f(float value)
{
    sub_007bd830(value, &g_00a7fb98);
}
