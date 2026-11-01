// from server: 100% by auto
struct P_func_00691930 { void g(); };
struct S_func_00691930 {
    char pad[8];
    P_func_00691930* m_p;
    void f();
};
void S_func_00691930::f()
{
    m_p->g();
}
