// from server: 100% by auto
struct P_func_0062db90 { void g(); };
struct S_func_0062db90 {
    char pad[4];
    P_func_0062db90* m_p;
    void f();
};
void S_func_0062db90::f()
{
    m_p->g();
}
