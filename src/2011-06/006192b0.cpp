// from server: 100% by auto
struct P_func_006192b0 { void g(); };
struct S_func_006192b0 {
    char pad[516];
    P_func_006192b0* m_p;
    void f();
};
void S_func_006192b0::f()
{
    m_p->g();
}
