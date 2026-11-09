// from server: 100% by auto
struct P_func_005abd60 { void g(); };
struct S_func_005abd60 {
    char pad[8];
    P_func_005abd60* m_p;
    void f();
};
void S_func_005abd60::f()
{
    m_p->g();
}
