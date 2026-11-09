// from server: 37% by atomic.potato
struct S_func_0068c550 {
    char pad0[144];
    char m_initialized;
    float m_value;
    void initialize();
    float f();
};

void S_func_0068c550::initialize()
{
}

float S_func_0068c550::f()
{
    if (!m_initialized)
        initialize();
    return m_value;
}
