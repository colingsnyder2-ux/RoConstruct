// from server: 100% by atomic.potato
struct Backpack
{
    char pad0[148];
    char m_flag;
    char pad1[15];
    int m_value;
    void f(void *);
};

void Backpack::f(void *value)
{
    if (m_flag)
        m_value = *(int *)value;
}
