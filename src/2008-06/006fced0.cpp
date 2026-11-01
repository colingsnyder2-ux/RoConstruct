// from server: 100% by auto
struct P_func_006fced0 { void g(); };
struct S_func_006fced0 {
    char pad[68];
    P_func_006fced0* m_p;
    void f();
};
void S_func_006fced0::f()
{
    m_p->g();
}
