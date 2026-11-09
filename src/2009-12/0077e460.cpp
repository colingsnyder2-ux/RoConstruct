// from server: 50% by atomic.potato
extern "C" void __stdcall sub_004f8a70(float);

struct S_func_0077e460 {
    char pad0[64];
    double m_value;
    char pad1[156];
    float m_scale;
    void f(void* arg1, float arg2);
};

void S_func_0077e460::f(void* arg1, float arg2)
{
    m_value = 0.0;
    sub_004f8a70(((S_func_0077e460*)arg1)->m_scale * arg2);
}
