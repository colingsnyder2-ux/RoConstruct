// from server: 100% by auto
struct P_func_005e9060 { void g(); };
struct S_func_005e9060 {
    char pad[32];
    P_func_005e9060* m_p;
    void f();
};
void S_func_005e9060::f()
{
    m_p->g();
}
