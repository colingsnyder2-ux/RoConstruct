// from server: 100% by auto
struct P_func_006cb440 { void g(); };
struct S_func_006cb440 {
    char pad[256];
    P_func_006cb440* m_p;
    void f();
};
void S_func_006cb440::f()
{
    m_p->g();
}
