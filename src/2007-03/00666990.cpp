// from server: 100% by auto
struct P_func_00666990 { void g(); };
struct S_func_00666990 {
    char pad[64];
    P_func_00666990* m_p;
    void f();
};
void S_func_00666990::f()
{
    m_p->g();
}
