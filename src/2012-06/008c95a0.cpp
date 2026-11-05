// from server: 61% by atomic.potato
extern "C" void __stdcall sub_414da0(int);

struct S_func_008c95a0 {
    char pad0[132];
    float m_value;
    void f(float value);
};

void S_func_008c95a0::f(float value)
{
    if (m_value != value) {
        m_value = value;
        sub_414da0(0xe53ae8);
    }
}
