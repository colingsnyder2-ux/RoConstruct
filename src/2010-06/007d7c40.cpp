// from server: 100% by auto
struct P_func_007d7c40 { void g(); };
struct S_func_007d7c40 {
    P_func_007d7c40* m_p;
    void f();
};
void S_func_007d7c40::f()
{
    m_p->g();
}
