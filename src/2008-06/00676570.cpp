// from server: 100% by auto
struct P_func_00676570 { void g(); };
struct S_func_00676570 {
    char pad[4];
    P_func_00676570* m_p;
    void f();
};
void S_func_00676570::f()
{
    m_p->g();
}
