// from server: 100% by auto
struct P_func_006c1af0 { void g(); };
struct S_func_006c1af0 {
    char pad[12];
    P_func_006c1af0* m_p;
    void f();
};
void S_func_006c1af0::f()
{
    m_p->g();
}
