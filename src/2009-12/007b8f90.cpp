// from server: 62% by atomic.potato
struct S_func_007d9f70
{
    void f(void *a1);
};

struct S_func_007bab80
{
    char pad0[8];
    S_func_007d9f70 *m_x;
    void f(void *a1);
};

struct S_func_007b2f30
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct AssemblyStage
{
    char pad0[8];
    S_func_007bab80 *m_x;
    void f(void *a1);
};

void AssemblyStage::f(void *a1)
{
    S_func_007d9f70 *p = (S_func_007d9f70 *)a1;
    p->f(a1);
    m_x->f(a1);
    ((S_func_007b2f30 *)a1)->f((int)this);
}
