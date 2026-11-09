// from server: 100% by auto
struct P_func_00685390 { void g(); };
struct S_func_00685390 {
    char pad[64];
    P_func_00685390* m_p;
    void f();
};
void S_func_00685390::f()
{
    m_p->g();
}
