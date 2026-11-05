// from server: 75% by atomic.potato
struct S_func_005a5c50
{
    char pad[152];
    char *m_value;
    void f();
};

void S_func_005a5c50::f()
{
    if (m_value != 0)
        (*(void (**)(void *))(*(char **)m_value + 8))(m_value);
}
