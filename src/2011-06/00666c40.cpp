// from server: 100% by atomic.potato
struct S_func_00666c40 {
    char pad[8];
    unsigned char m_enabled;
    unsigned char m_value;
    int f();
};

int S_func_00666c40::f()
{
    if (m_enabled)
        return 1;
    return m_value ? -1 : 0;
}
