// from server: 100% by auto
struct P_func_008f98d0 { void g(); };
struct S_func_008f98d0 {
    char pad[52];
    P_func_008f98d0* m_p;
    void f();
};
void S_func_008f98d0::f()
{
    m_p->g();
}
