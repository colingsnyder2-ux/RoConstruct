// from server: 100% by auto
struct P_func_005e79d0 { void g(); };
struct S_func_005e79d0 {
    char pad[2772];
    P_func_005e79d0* m_p;
    void f();
};
void S_func_005e79d0::f()
{
    m_p->g();
}
