// from server: 100% by auto
struct P_func_0062da80 { void g(); };
struct S_func_0062da80 {
    char pad[4];
    P_func_0062da80* m_p;
    void f();
};
void S_func_0062da80::f()
{
    m_p->g();
}
