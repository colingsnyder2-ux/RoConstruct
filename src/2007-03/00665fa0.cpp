// from server: 100% by auto
struct P_func_00665fa0 { void g(); };
struct S_func_00665fa0 {
    char pad[252];
    P_func_00665fa0* m_p;
    void f();
};
void S_func_00665fa0::f()
{
    m_p->g();
}
