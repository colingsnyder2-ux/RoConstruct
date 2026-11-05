// from server: 100% by colin
struct S_func_006e2400 {
    char pad0[0x1c0];
    int m_field1c0;
    int helper();
    int f();
};

int S_func_006e2400::f()
{
    if (helper() == 0)
        return 0;
    return m_field1c0 == 0;
}
