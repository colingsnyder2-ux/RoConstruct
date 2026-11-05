// from server: 43% by atomic.potato
struct S_func_005e0090
{
    char pad0[12];

    struct Container
    {
        int begin;
        int count;

        void reserve(int, int);
    } m_container;

    int m_value;

    int f();
};

void S_func_005e0090::Container::reserve(int, int)
{
}

int S_func_005e0090::f()
{
    m_container.reserve(m_value + 1, 0);
    return m_container.begin + m_container.count * 52 - 52;
}
