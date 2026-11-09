// from server: 46% by atomic.potato
struct S_func_0092b320 {
    int m_value0;
    void f(int value);
};

void S_func_0092b320::f(int value)
{
    if (value == 0) {
        if (m_value0 == 1)
            m_value0 = 0;
    } else if (value == 2) {
        m_value0 = 2;
    }
}
