// from server: 100% by auto
struct P_func_006713a0 { void g(); };
struct S_func_006713a0 {
    P_func_006713a0* m_p;
    void f();
};
void S_func_006713a0::f()
{
    m_p->g();
}
