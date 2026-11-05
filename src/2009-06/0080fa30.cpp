// from server: 100% by auto
struct P_func_0080fa30 { void g(); };
struct S_func_0080fa30 {
    char pad[132];
    P_func_0080fa30* m_p;
    void f();
};
void S_func_0080fa30::f()
{
    m_p->g();
}
