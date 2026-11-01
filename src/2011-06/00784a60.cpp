// from server: 100% by auto
struct P_func_00784a60 { void g(); };
struct S_func_00784a60 {
    char pad[32];
    P_func_00784a60* m_p;
    void f();
};
void S_func_00784a60::f()
{
    m_p->g();
}
