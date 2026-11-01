// from server: 100% by auto
struct P_func_00784b90 { void g(); };
struct S_func_00784b90 {
    char pad[28];
    P_func_00784b90* m_p;
    void f();
};
void S_func_00784b90::f()
{
    m_p->g();
}
