// from server: 100% by auto
struct P_func_005cce00 { void g(); };
struct S_func_005cce00 {
    char pad[2728];
    P_func_005cce00* m_p;
    void f();
};
void S_func_005cce00::f()
{
    m_p->g();
}
