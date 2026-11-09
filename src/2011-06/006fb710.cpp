// from server: 46% by atomic.potato
struct S_func_006fb710 {
    char pad0[0x10];
    int m_10;
    int m_14;
    void f(int a, float* b);
};

void S_func_006fb710::f(int a, float* b)
{
    S_func_006fb710* p;
    if (a != 0)
        p = (S_func_006fb710*)((char*)a - 0x1c);
    else
        p = 0;

    float v[3];
    v[0] = b[0];
    v[1] = b[1];
    v[2] = b[2];

    typedef void (__thiscall *Fn)(void*, float*);
    Fn fn = (Fn)m_10;
    fn((char*)p + m_14, v);
}
