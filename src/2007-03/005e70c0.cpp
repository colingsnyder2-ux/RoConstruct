// from server: 100% by auto
struct P_func_005e70c0 { void g(); };
struct S_func_005e70c0 {
    P_func_005e70c0* m_p;
    void f();
};
void S_func_005e70c0::f()
{
    m_p->g();
}
