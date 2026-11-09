// from server: 100% by auto
struct P_func_00847620 { void g(); };
struct S_func_00847620 {
    char pad[444];
    P_func_00847620* m_p;
    void f();
};
void S_func_00847620::f()
{
    m_p->g();
}
