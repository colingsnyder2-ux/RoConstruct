// from server: 100% by atomic.potato
struct S_func_0064bb20 {
    char pad0[4];
    unsigned char m_enabled;
    unsigned char m_value;
    int f();
};

int S_func_0064bb20::f()
{
    if (m_enabled)
        return 1;
    return (m_value != 0) ? -1 : 0;
}
