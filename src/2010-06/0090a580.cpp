// from server: 100% by tester
struct S_func_00967ac0 {
    char pad0[0x1c];
    int m_begin;
    int m_end;
    int f();
};

int S_func_00967ac0::f()
{
    return (m_end - m_begin) >> 3;
}
