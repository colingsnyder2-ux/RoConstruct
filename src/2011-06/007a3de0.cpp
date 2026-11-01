// from server: 100% by auto
struct P_func_007a3de0 { void g(); };
struct S_func_007a3de0 {
    char pad[20];
    P_func_007a3de0* m_p;
    void f();
};
void S_func_007a3de0::f()
{
    m_p->g();
}
