// from server: 100% by auto
struct P_func_00719e80 { void g(); };
struct S_func_00719e80 {
    char pad[216];
    P_func_00719e80* m_p;
    void f();
};
void S_func_00719e80::f()
{
    m_p->g();
}
