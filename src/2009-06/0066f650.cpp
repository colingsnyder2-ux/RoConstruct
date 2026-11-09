// from server: 100% by why2
struct S_func_0066f650 {
    char pad0[0x10];
    int m_key;
    char pad14[4];
    int m_value_if_equal;
    int m_value_otherwise;
    int f(int key);
};

int S_func_0066f650::f(int key)
{
    if (key == m_key)
        return m_value_if_equal;
    return m_value_otherwise;
}
