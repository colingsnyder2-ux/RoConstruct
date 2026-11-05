// from server: 100% by auto
struct P_func_00697160 { void g(); };
struct S_func_00697160 {
    char pad[320];
    P_func_00697160* m_p;
    void f();
};
void S_func_00697160::f()
{
    m_p->g();
}
