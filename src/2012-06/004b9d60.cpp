// from server: 100% by auto
struct P_func_004b9d60 { void g(); };
struct S_func_004b9d60 {
    char pad[64];
    P_func_004b9d60* m_p;
    void f();
};
void S_func_004b9d60::f()
{
    m_p->g();
}
