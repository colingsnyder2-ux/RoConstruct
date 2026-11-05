// from server: 100% by auto
struct P_func_0063a800 { void g(); };
struct S_func_0063a800 {
    char pad[152];
    P_func_0063a800* m_p;
    void f();
};
void S_func_0063a800::f()
{
    m_p->g();
}
