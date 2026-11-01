// from server: 100% by auto
struct P_func_005b3030 { void g(); };
struct S_func_005b3030 {
    char pad[8];
    P_func_005b3030* m_p;
    void f();
};
void S_func_005b3030::f()
{
    m_p->g();
}
