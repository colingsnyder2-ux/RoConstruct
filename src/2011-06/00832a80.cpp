// from server: 100% by auto
struct P_func_00832a80 { void g(); };
struct S_func_00832a80 {
    char pad[256];
    P_func_00832a80* m_p;
    void f();
};
void S_func_00832a80::f()
{
    m_p->g();
}
