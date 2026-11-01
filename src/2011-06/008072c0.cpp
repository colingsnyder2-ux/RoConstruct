// from server: 100% by auto
struct S_func_008072c0 {
    char pad0[80];
    int m_x;
    int* f();
};
int* S_func_008072c0::f()
{
    return &m_x;
}
