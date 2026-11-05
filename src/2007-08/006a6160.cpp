// from server: 100% by auto
struct P_func_006a6160 { void g(); };
struct S_func_006a6160 {
    char pad[444];
    P_func_006a6160* m_p;
    void f();
};
void S_func_006a6160::f()
{
    m_p->g();
}
