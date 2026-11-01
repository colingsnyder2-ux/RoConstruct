// from server: 100% by auto
struct P_func_00675ca0 { void g(); };
struct S_func_00675ca0 {
    char pad[60];
    P_func_00675ca0* m_p;
    void f();
};
void S_func_00675ca0::f()
{
    m_p->g();
}
