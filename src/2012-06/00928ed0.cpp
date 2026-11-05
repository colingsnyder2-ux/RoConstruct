// from server: 86% by atomic.potato
struct S_func_00928ed0 {
    char pad0[0x60];
    int m_60;
    int m_64;
    float m_68;
    int m_6c;
    int m_70;
    int m_74;
    void f(int, int, int, int, int, int);
};

struct S_sub_008944d0 {
    void g(int, int, int);
};

void S_func_00928ed0::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    ((S_sub_008944d0*)this)->g(a1, a2, a3);
    m_64 = a6;
    m_60 = 0;
    *(int*)this = 0xbfd80c;
    m_68 = *(float*)&a4;
    int* p = (int*)a5;
    m_6c = p[0];
    m_70 = p[1];
    m_74 = p[2];
}
