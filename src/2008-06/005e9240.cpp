// from server: 100% by auto
struct P_func_005e9240 { void g(); };
struct S_func_005e9240 {
    char pad[136];
    P_func_005e9240* m_p;
    void f();
};
void S_func_005e9240::f()
{
    m_p->g();
}
