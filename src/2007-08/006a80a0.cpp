// from server: 100% by auto
struct P_func_006a80a0 { void g(); };
struct S_func_006a80a0 {
    char pad[608];
    P_func_006a80a0* m_p;
    void f();
};
void S_func_006a80a0::f()
{
    m_p->g();
}
