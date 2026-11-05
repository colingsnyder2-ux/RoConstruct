// from server: 100% by auto
struct P_func_00875e20 { void g(); };
struct S_func_00875e20 {
    char pad[176];
    P_func_00875e20* m_p;
    void f();
};
void S_func_00875e20::f()
{
    m_p->g();
}
