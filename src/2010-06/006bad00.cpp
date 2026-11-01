// from server: 100% by auto
struct S_func_006bad00 {
    char pad0[248];
    int m_x;
    int* f();
};
int* S_func_006bad00::f()
{
    return &m_x;
}
