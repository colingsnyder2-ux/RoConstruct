// from server: 100% by auto
struct P_func_006544c0 { void g(); };
struct S_func_006544c0 {
    char pad[28];
    P_func_006544c0* m_p;
    void f();
};
void S_func_006544c0::f()
{
    m_p->g();
}
