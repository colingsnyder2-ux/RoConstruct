// from server: 100% by auto
struct P_func_005b3040 { void g(); };
struct S_func_005b3040 {
    char pad[8];
    P_func_005b3040* m_p;
    void f();
};
void S_func_005b3040::f()
{
    m_p->g();
}
