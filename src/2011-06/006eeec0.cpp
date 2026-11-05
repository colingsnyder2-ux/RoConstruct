// from server: 70% by atomic.potato
struct S_func_006eeec0 {
    char pad0[216];
    int *m_data;

    void f(int *out);
};

void __thiscall S_func_006eeec0::f(int *out)
{
    out[0] = m_data[0x7c / 4];
    out[1] = m_data[0x80 / 4];
    out[2] = m_data[0x84 / 4];
    out[3] = m_data[0x88 / 4];
}
