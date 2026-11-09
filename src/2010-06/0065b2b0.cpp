// from server: 100% by auto
struct P_func_0065b2b0 { void g(); };
struct S_func_0065b2b0 {
    char pad[16];
    P_func_0065b2b0* m_p;
    void f();
};
void S_func_0065b2b0::f()
{
    m_p->g();
}
