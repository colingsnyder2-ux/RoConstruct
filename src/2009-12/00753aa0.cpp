// from server: 52% by atomic.potato
struct S_00753aa0 {
    char pad0[752];
    int* m_value;
    int f();
};

int S_00753aa0::f()
{
    if (m_value == 0)
        return 0;
    return m_value[1] != 0;
}
