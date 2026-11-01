// from server: 100% by auto
struct P_func_00654340 { void g(); };
struct S_func_00654340 {
    char pad[172];
    P_func_00654340* m_p;
    void f();
};
void S_func_00654340::f()
{
    m_p->g();
}
