// from server: 100% by auto
struct P_func_005d5700 { void g(); };
struct S_func_005d5700 {
    char pad[140];
    P_func_005d5700* m_p;
    void f();
};
void S_func_005d5700::f()
{
    m_p->g();
}
