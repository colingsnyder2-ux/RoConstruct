// from server: 100% by auto
struct P_func_00810f60 { void g(); };
struct S_func_00810f60 {
    char pad[52];
    P_func_00810f60* m_p;
    void f();
};
void S_func_00810f60::f()
{
    m_p->g();
}
