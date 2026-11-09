// from server: 100% by auto
struct P_func_00638ae0 { void g(); };
struct S_func_00638ae0 {
    char pad[40];
    P_func_00638ae0* m_p;
    void f();
};
void S_func_00638ae0::f()
{
    m_p->g();
}
