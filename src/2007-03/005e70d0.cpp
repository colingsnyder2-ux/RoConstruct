// from server: 100% by auto
struct P_func_005e70d0 { void g(); };
struct S_func_005e70d0 {
    P_func_005e70d0* m_p;
    void f();
};
void S_func_005e70d0::f()
{
    m_p->g();
}
