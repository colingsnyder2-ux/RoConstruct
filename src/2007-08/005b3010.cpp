// from server: 100% by auto
struct P_func_005b3010 { void g(); };
struct S_func_005b3010 {
    char pad[8];
    P_func_005b3010* m_p;
    void f();
};
void S_func_005b3010::f()
{
    m_p->g();
}
