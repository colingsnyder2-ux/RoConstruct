// from server: 100% by auto
struct P_func_00665fb0 { void g(); };
struct S_func_00665fb0 {
    char pad[2712];
    P_func_00665fb0* m_p;
    void f();
};
void S_func_00665fb0::f()
{
    m_p->g();
}
