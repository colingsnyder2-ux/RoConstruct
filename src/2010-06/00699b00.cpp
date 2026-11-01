// from server: 100% by auto
struct P_func_00699b00 { void g(); };
struct S_func_00699b00 {
    char pad[208];
    P_func_00699b00* m_p;
    void f();
};
void S_func_00699b00::f()
{
    m_p->g();
}
