// from server: 40% by atomic.potato
struct EdgeStage
{
    int pad0;
    int m_field;
    void f(int);
};

struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int);
};

void S_func_007637e0::f(int a1)
{
    m_x = (int)a1;
}

extern "C" void func_00791de0(int, int);

void EdgeStage::f(int a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)this;
    p->f(a1);
    func_00791de0(m_field, a1);
}
