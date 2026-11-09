// from server: 100% by auto
struct P_func_00829bc0 { void g(); };
struct S_func_00829bc0 {
    char pad[188];
    P_func_00829bc0* m_p;
    void f();
};
void S_func_00829bc0::f()
{
    m_p->g();
}
