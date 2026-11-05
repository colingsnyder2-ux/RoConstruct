// from server: 64% by atomic.potato
struct S_func_007637e0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_0078d340 {
    char pad0[8];
    S_func_007637e0* m_p;

    void func_0078d340(int a1);
};

void func_0078d2c0(int* a1, void* a2, void* a3);

void S_0078d340::func_0078d340(int a1)
{
    S_func_007637e0* p = m_p;
    p->f(a1);
    m_p->f(a1);
    func_0078d2c0((int*)(a1 + 8), (void*)0x760d40, m_p);
}
