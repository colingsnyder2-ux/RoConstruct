// from server: 100% by auto
struct P_func_00794690 { void g(); };
struct S_func_00794690 {
    char pad[52];
    P_func_00794690* m_p;
    void f();
};
void S_func_00794690::f()
{
    m_p->g();
}
