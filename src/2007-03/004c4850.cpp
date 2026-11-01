// from server: 100% by auto
struct P_func_004c4850 { void g(); };
struct S_func_004c4850 {
    char pad[96];
    P_func_004c4850* m_p;
    void f();
};
void S_func_004c4850::f()
{
    m_p->g();
}
