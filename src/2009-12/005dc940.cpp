// from server: 100% by auto
struct P_func_005dc940 { void g(); };
struct S_func_005dc940 {
    char pad[8];
    P_func_005dc940* m_p;
    void f();
};
void S_func_005dc940::f()
{
    m_p->g();
}
