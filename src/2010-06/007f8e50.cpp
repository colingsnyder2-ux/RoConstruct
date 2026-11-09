// from server: 100% by auto
struct P_func_007f8e50 { void g(); };
struct S_func_007f8e50 {
    char pad[256];
    P_func_007f8e50* m_p;
    void f();
};
void S_func_007f8e50::f()
{
    m_p->g();
}
