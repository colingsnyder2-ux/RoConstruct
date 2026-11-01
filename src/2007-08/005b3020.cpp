// from server: 100% by auto
struct P_func_005b3020 { void g(); };
struct S_func_005b3020 {
    char pad[8];
    P_func_005b3020* m_p;
    void f();
};
void S_func_005b3020::f()
{
    m_p->g();
}
