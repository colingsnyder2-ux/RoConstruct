// from server: 100% by auto
struct P_func_00649050 { void g(); };
struct S_func_00649050 {
    P_func_00649050* m_p;
    void f();
};
void S_func_00649050::f()
{
    m_p->g();
}
