// from server: 100% by auto
struct P_func_00743a30 { void g(); };
struct S_func_00743a30 {
    char pad[256];
    P_func_00743a30* m_p;
    void f();
};
void S_func_00743a30::f()
{
    m_p->g();
}
