// from server: 100% by auto
struct P_func_0081e900 { void g(); };
struct S_func_0081e900 {
    char pad[256];
    P_func_0081e900* m_p;
    void f();
};
void S_func_0081e900::f()
{
    m_p->g();
}
