// from server: 100% by auto
struct P_func_00604a30 { void g(); };
struct S_func_00604a30 {
    char pad[8];
    P_func_00604a30* m_p;
    void f();
};
void S_func_00604a30::f()
{
    m_p->g();
}
