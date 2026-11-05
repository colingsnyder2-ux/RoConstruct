// from server: 100% by auto
struct P_func_007148e0 { void g(); };
struct S_func_007148e0 {
    char pad[36];
    P_func_007148e0* m_p;
    void f();
};
void S_func_007148e0::f()
{
    m_p->g();
}
