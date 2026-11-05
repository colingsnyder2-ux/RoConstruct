// from server: 60% by atomic.potato
struct S_func_00a34460 {
    char pad0[24];
    int m_x;
    void f(int a1);
};

struct S {
    char pad0[0x94];
    int m_field94;
    char pad1[0xf8 - 0x98];
    S_func_00a34460* m_fieldF8;
    void f(int a1);
};

void S::f(int a1)
{
    if (m_field94 != a1)
    {
        S_func_00a34460* p = m_fieldF8;
        m_field94 = a1;
        if (p)
        {
            p->f(a1);
        }
        extern void __stdcall sub_414da0(int);
        sub_414da0(0xe21110);
    }
}
