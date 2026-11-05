// from server: 90% by atomic.potato
struct S_func_00726190 {
    char pad0[176];
    unsigned int m_value;
    void f(unsigned int value);
};

void S_func_00726190::f(unsigned int value)
{
    m_value = (m_value & ~4u) | (value ? 0u : 4u);
}
