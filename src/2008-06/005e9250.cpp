// from server: 100% by auto
struct P_func_005e9250 { void g(); };
struct S_func_005e9250 {
    char pad[136];
    P_func_005e9250* m_p;
    void f();
};
void S_func_005e9250::f()
{
    m_p->g();
}
