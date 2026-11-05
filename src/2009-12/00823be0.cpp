// from server: 100% by auto
struct P_func_00823be0 { void g(); };
struct S_func_00823be0 {
    P_func_00823be0* m_p;
    void f();
};
void S_func_00823be0::f()
{
    m_p->g();
}
