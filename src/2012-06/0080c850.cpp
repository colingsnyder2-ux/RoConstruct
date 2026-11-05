// from server: 37% by atomic.potato
extern "C" void __cdecl sub_414da0(float, int);

struct S_func_0080c850 {
    char pad0[548];
    float m_value;
    void f(float);
};

void S_func_0080c850::f(float value)
{
    if (m_value != value) {
        m_value = value;
        sub_414da0(value, 0xE4FCD4);
    }
}
