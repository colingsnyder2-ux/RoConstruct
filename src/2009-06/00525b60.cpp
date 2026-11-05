// from server: 100% by auto
struct I_func_00525b60 {
    char pad[524];
    int m_x;
};
struct S_func_00525b60 {
    char pad[20];
    I_func_00525b60* m_p;
    int f();
};
int S_func_00525b60::f()
{
    return m_p->m_x;
}
