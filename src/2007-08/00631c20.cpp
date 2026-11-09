// from server: 100% by auto
struct P_func_00631c20 { void g(); };
struct S_func_00631c20 {
    char pad[188];
    P_func_00631c20* m_p;
    void f();
};
void S_func_00631c20::f()
{
    m_p->g();
}
