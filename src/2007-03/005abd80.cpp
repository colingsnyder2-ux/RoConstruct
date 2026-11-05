// from server: 100% by auto
struct P_func_005abd80 { void g(); };
struct S_func_005abd80 {
    char pad[8];
    P_func_005abd80* m_p;
    void f();
};
void S_func_005abd80::f()
{
    m_p->g();
}
