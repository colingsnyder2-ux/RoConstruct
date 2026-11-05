// from server: 100% by auto
struct P_func_00832a70 { void g(); };
struct S_func_00832a70 {
    char pad[256];
    P_func_00832a70* m_p;
    void f();
};
void S_func_00832a70::f()
{
    m_p->g();
}
