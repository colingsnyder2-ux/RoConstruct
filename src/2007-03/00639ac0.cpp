// from server: 100% by auto
struct I_func_00639ac0 {
    char pad[44];
    int m_x;
};
struct S_func_00639ac0 {
    char pad[244];
    I_func_00639ac0* m_p;
    int f();
};
int S_func_00639ac0::f()
{
    return m_p->m_x;
}
