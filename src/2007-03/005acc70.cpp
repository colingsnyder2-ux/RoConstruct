// from server: 100% by auto
struct P_func_005acc70 { void g(); };
struct S_func_005acc70 {
    char pad[52];
    P_func_005acc70* m_p;
    void f();
};
void S_func_005acc70::f()
{
    m_p->g();
}
