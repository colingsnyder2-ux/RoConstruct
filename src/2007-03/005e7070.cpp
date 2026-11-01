// from server: 100% by auto
struct P_func_005e7070 { void g(); };
struct S_func_005e7070 {
    P_func_005e7070* m_p;
    void f();
};
void S_func_005e7070::f()
{
    m_p->g();
}
