// from server: 100% by auto
struct P_func_0085fb00 { void g(); };
struct S_func_0085fb00 {
    char pad[68];
    P_func_0085fb00* m_p;
    void f();
};
void S_func_0085fb00::f()
{
    m_p->g();
}
