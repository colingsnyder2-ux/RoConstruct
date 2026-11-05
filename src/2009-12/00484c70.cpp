// from server: 49% by atomic.potato
struct S_func_00484c70 {
    int m_value;
    void f(int value);
};

void S_func_00484c70::f(int value)
{
    if (value == 0) {
        if (m_value == 1)
            m_value = 0;
    } else if (value - 2 == 0) {
        m_value = 2;
    }
}
