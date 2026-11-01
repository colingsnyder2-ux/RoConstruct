// from server: 100% by auto
struct P_func_008f7ed0 { void g(); };
struct S_func_008f7ed0 {
    char pad[132];
    P_func_008f7ed0* m_p;
    void f();
};
void S_func_008f7ed0::f()
{
    m_p->g();
}
