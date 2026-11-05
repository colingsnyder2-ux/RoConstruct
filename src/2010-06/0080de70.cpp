// from server: 100% by auto
struct P_func_0080de70 { void g(); };
struct S_func_0080de70 {
    char pad[8];
    P_func_0080de70* m_p;
    void f();
};
void S_func_0080de70::f()
{
    m_p->g();
}
