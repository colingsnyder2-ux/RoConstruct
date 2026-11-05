// from server: 100% by auto
struct P_func_00804620 { void g(); };
struct S_func_00804620 {
    char pad[68];
    P_func_00804620* m_p;
    void f();
};
void S_func_00804620::f()
{
    m_p->g();
}
