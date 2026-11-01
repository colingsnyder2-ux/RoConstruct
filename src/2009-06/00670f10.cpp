// from server: 100% by auto
struct P_func_00670f10 { void g(); };
struct S_func_00670f10 {
    char pad[228];
    P_func_00670f10* m_p;
    void f();
};
void S_func_00670f10::f()
{
    m_p->g();
}
