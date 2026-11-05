// from server: 23% by atomic.potato
struct S_00750fd0
{
    int m_padding;
    int m_value;
    int f();
};

int S_00750fd0::f()
{
    while (m_value != 0)
        return f();
    return 0;
}
