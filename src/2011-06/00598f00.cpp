// from server: 100% by auto
struct P_func_00598f00 { void g(); };
struct S_func_00598f00 {
    char pad[148];
    P_func_00598f00* m_p;
    void f();
};
void S_func_00598f00::f()
{
    m_p->g();
}
