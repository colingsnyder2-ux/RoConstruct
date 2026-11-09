// from server: 100% by auto
struct P_func_006e3f90 { void g(); };
struct S_func_006e3f90 {
    char pad[252];
    P_func_006e3f90* m_p;
    void f();
};
void S_func_006e3f90::f()
{
    m_p->g();
}
