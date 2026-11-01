// from server: 100% by auto
struct P_func_00659b50 { void g(); };
struct S_func_00659b50 {
    char pad[172];
    P_func_00659b50* m_p;
    void f();
};
void S_func_00659b50::f()
{
    m_p->g();
}
