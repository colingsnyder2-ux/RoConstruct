// from server: 100% by auto
struct P_func_005d56f0 { void g(); };
struct S_func_005d56f0 {
    char pad[140];
    P_func_005d56f0* m_p;
    void f();
};
void S_func_005d56f0::f()
{
    m_p->g();
}
