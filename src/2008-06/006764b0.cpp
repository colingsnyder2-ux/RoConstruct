// from server: 100% by auto
struct P_func_006764b0 { void g(); };
struct S_func_006764b0 {
    char pad[4];
    P_func_006764b0* m_p;
    void f();
};
void S_func_006764b0::f()
{
    m_p->g();
}
