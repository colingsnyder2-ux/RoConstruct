// from server: 100% by auto
struct P_func_00699b10 { void g(); };
struct S_func_00699b10 {
    char pad[216];
    P_func_00699b10* m_p;
    void f();
};
void S_func_00699b10::f()
{
    m_p->g();
}
