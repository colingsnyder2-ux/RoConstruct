// from server: 100% by auto
struct P_func_00697170 { void g(); };
struct S_func_00697170 {
    char pad[320];
    P_func_00697170* m_p;
    void f();
};
void S_func_00697170::f()
{
    m_p->g();
}
