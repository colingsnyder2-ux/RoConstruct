// from server: 100% by auto
struct P_func_00719e60 { void g(); };
struct S_func_00719e60 {
    char pad[208];
    P_func_00719e60* m_p;
    void f();
};
void S_func_00719e60::f()
{
    m_p->g();
}
