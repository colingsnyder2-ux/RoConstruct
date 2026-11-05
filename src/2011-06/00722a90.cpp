// from server: 100% by atomic.potato
struct S_func_00722a90 {
    char pad0[0x94];
    int m_field94;
    char pad1[4];
    int m_field9c;
    S_func_00722a90* f(int a1, int a2);
};

struct S_sub_00722a30 {
    void g(int a1);
};

S_func_00722a90* S_func_00722a90::f(int a1, int a2)
{
    if (a2 != 0) {
        m_field94 = 0xa9cc9c;
    }
    ((S_sub_00722a30*)this)->g(a1);
    m_field9c = 0;
    return this;
}
