// from server: 100% by auto
struct S_func_004b7910 {
    char pad0[8];
    int m_x;
    int* f();
};
int* S_func_004b7910::f()
{
    return &m_x;
}
