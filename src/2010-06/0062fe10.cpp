// from server: 100% by auto
struct P_func_0062fe10 { void g(); };
struct S_func_0062fe10 {
    char pad[180];
    P_func_0062fe10* m_p;
    void f();
};
void S_func_0062fe10::f()
{
    m_p->g();
}
