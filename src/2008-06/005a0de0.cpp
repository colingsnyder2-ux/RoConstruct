// from server: 100% by auto
struct P_func_005a0de0 { void g(); };
struct S_func_005a0de0 {
    char pad[740];
    P_func_005a0de0* m_p;
    void f();
};
void S_func_005a0de0::f()
{
    m_p->g();
}
