// from server: 100% by auto
struct P_func_00804610 { void g(); };
struct S_func_00804610 {
    char pad[68];
    P_func_00804610* m_p;
    void f();
};
void S_func_00804610::f()
{
    m_p->g();
}
