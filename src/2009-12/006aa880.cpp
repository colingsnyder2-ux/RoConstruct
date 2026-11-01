// from server: 100% by auto
struct S_func_006aa880 {
    char pad0[200];
    int m_x;
    int* f();
};
int* S_func_006aa880::f()
{
    return &m_x;
}
