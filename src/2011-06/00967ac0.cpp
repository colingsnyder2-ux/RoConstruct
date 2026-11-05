// from server: 100% by atomic.potato
struct S_func_00967ac0 {
    char pad0[0x14];
    int m_begin;
    int m_end;
    int f();
};

int S_func_00967ac0::f()
{
    return (m_end - m_begin) >> 3;
}
