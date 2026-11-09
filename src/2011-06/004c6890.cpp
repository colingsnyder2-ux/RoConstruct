// from server: 52% by atomic.potato
struct S_func_004c6890 {
    int m_value;
    void f();
};

void S_func_004c6890::f()
{
    if (m_value != 0)
        f();
}
