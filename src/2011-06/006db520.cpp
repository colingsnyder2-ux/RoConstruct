// from server: 100% by auto
struct P_func_006db520 { void g(); };
struct S_func_006db520 {
    char pad[188];
    P_func_006db520* m_p;
    void f();
};
void S_func_006db520::f()
{
    m_p->g();
}
