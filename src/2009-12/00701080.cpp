// from server: 100% by auto
struct P_func_00701080 { void g(); };
struct S_func_00701080 {
    char pad[60];
    P_func_00701080* m_p;
    void f();
};
void S_func_00701080::f()
{
    m_p->g();
}
