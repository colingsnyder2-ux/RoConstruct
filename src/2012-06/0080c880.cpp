// from server: 61% by atomic.potato
extern "C" void __stdcall RBX_Update(unsigned int);

struct S_func_0080c880 {
    char pad0[564];
    float m_value;
    void f(float value);
};

void S_func_0080c880::f(float value)
{
    if (m_value != value) {
        m_value = value;
        RBX_Update(0x00e4fdb0);
    }
}
