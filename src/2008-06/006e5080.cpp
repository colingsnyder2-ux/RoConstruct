// from server: 100% by auto
struct P_func_006e5080 { void g(); };
struct S_func_006e5080 {
    char pad[228];
    P_func_006e5080* m_p;
    void f();
};
void S_func_006e5080::f()
{
    m_p->g();
}
