// from server: 100% by auto
struct P_func_00685f80 { void g(); };
struct S_func_00685f80 {
    P_func_00685f80* m_p;
    void f();
};
void S_func_00685f80::f()
{
    m_p->g();
}
