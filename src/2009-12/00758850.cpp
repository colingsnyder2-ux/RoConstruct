// from server: 78% by atomic.potato
struct S_func_00758850 {
    char pad0[0x17c];
    float m_x;
    float m_y;
    float m_z;
    void* f(void*);
};

extern "C" void __stdcall sub_006b1430(void*, float, float, float);

void* S_func_00758850::f(void* a)
{
    sub_006b1430(a, m_x, m_y, m_z);
    return a;
}
