// from server: 100% by auto
struct P_func_006a4b30 { void g(); };
struct S_func_006a4b30 {
    char pad[264];
    P_func_006a4b30* m_p;
    void f();
};
void S_func_006a4b30::f()
{
    m_p->g();
}
