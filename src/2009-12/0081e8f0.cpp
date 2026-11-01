// from server: 100% by auto
struct P_func_0081e8f0 { void g(); };
struct S_func_0081e8f0 {
    char pad[256];
    P_func_0081e8f0* m_p;
    void f();
};
void S_func_0081e8f0::f()
{
    m_p->g();
}
