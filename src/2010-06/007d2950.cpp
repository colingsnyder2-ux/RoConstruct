// from server: 100% by auto
struct P_func_007d2950 { void g(); };
struct S_func_007d2950 {
    char pad[256];
    P_func_007d2950* m_p;
    void f();
};
void S_func_007d2950::f()
{
    m_p->g();
}
