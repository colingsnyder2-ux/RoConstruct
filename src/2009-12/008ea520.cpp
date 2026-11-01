// from server: 100% by auto
struct P_func_008ea520 { void g(); };
struct S_func_008ea520 {
    char pad[132];
    P_func_008ea520* m_p;
    void f();
};
void S_func_008ea520::f()
{
    m_p->g();
}
