// from server: 100% by atomic.potato
struct Backpack {
    char pad0[148];
    char m_ready;
    char pad1[11];
    int m_value;
    void f(void *);
};

void Backpack::f(void *value)
{
    if (m_ready)
        m_value = *(int *)value;
}
