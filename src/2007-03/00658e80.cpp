// from server: 100% by auto
struct P_func_00658e80 { void g(); };
struct S_func_00658e80 {
    char pad[244];
    P_func_00658e80* m_p;
    void f();
};
void S_func_00658e80::f()
{
    m_p->g();
}
