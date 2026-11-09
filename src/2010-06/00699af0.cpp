// from server: 100% by auto
struct P_func_00699af0 { void g(); };
struct S_func_00699af0 {
    char pad[208];
    P_func_00699af0* m_p;
    void f();
};
void S_func_00699af0::f()
{
    m_p->g();
}
