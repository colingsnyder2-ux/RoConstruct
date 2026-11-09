// from server: 100% by auto
struct P_func_006cb450 { void g(); };
struct S_func_006cb450 {
    char pad[256];
    P_func_006cb450* m_p;
    void f();
};
void S_func_006cb450::f()
{
    m_p->g();
}
