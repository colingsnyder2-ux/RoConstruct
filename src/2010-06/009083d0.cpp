// from server: 18% by atomic.potato
struct S_func_008cc5e0 {
    char pad0[2096];
    int m_x;
    int f();
};

int S_func_008cc5e0::f()
{
    return m_x;
}

struct S_func_009083d0 {
    char pad0[36];
    int m_x24;
    char pad1[15];
    char m_x58;
    char pad2[18311];
    int m_x47e0;
    void f();
};

void S_func_009083d0::f()
{
    S_func_008cc5e0* p = (S_func_008cc5e0*)m_x24;
    m_x58 = 1;
    p = *(S_func_008cc5e0**)((char*)p + 0x1e4);
    p = *(S_func_008cc5e0**)((char*)p + 0x47e0);
    p->f();
}
