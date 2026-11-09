// from server: 100% by auto
struct P_func_006cbd20 { void g(); };
struct S_func_006cbd20 {
    char pad[360];
    P_func_006cbd20* m_p;
    void f();
};
void S_func_006cbd20::f()
{
    m_p->g();
}
