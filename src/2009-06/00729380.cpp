// from server: 100% by auto
struct P_func_00729380 { void g(); };
struct S_func_00729380 {
    char pad[188];
    P_func_00729380* m_p;
    void f();
};
void S_func_00729380::f()
{
    m_p->g();
}
