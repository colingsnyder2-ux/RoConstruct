// from server: 100% by auto
struct P_func_0060cbf0 { void g(); };
struct S_func_0060cbf0 {
    P_func_0060cbf0* m_p;
    void f();
};
void S_func_0060cbf0::f()
{
    m_p->g();
}
