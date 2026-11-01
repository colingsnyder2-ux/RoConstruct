// from server: 100% by auto
struct P_func_00867960 { void g(); };
struct S_func_00867960 {
    char pad[176];
    P_func_00867960* m_p;
    void f();
};
void S_func_00867960::f()
{
    m_p->g();
}
