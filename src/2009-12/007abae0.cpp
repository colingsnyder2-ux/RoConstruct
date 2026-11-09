// from server: 36% by atomic.potato
extern "C" float g_00b7cc24;
extern "C" float g_00b7cc28;

struct S
{
    void f(float value);
};

void S::f(float value)
{
    float* p = reinterpret_cast<float*>(this);
    p[0] = value;
    p[1] = g_00b7cc24;
    p[2] = g_00b7cc28;
}
