// from server: 100% by auto
struct P_func_00719e70 { void g(); };
struct S_func_00719e70 {
    char pad[216];
    P_func_00719e70* m_p;
    void f();
};
void S_func_00719e70::f()
{
    m_p->g();
}
