// from server: 100% by auto
struct P_func_00713fc0 { void g(); };
struct S_func_00713fc0 {
    char pad[36];
    P_func_00713fc0* m_p;
    void f();
};
void S_func_00713fc0::f()
{
    m_p->g();
}
