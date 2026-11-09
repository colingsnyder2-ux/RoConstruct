// from server: 100% by auto
struct P_func_005e7760 { void g(); };
struct S_func_005e7760 {
    char pad[160];
    P_func_005e7760* m_p;
    void f();
};
void S_func_005e7760::f()
{
    m_p->g();
}
