// from server: 100% by auto
struct P_func_00685f90 { void g(); };
struct S_func_00685f90 {
    P_func_00685f90* m_p;
    void f();
};
void S_func_00685f90::f()
{
    m_p->g();
}
