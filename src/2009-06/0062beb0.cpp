// from server: 100% by auto
struct P_func_0062beb0 { void g(); };
struct S_func_0062beb0 {
    char pad[336];
    P_func_0062beb0* m_p;
    void f();
};
void S_func_0062beb0::f()
{
    m_p->g();
}
