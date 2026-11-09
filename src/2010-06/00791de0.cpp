// from server: 45% by atomic.potato
struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = a1;
}

extern "C" void func_00761660(void *, void *);

struct ContactStage
{
    char pad0[8];
    void f(void *);
};

void ContactStage::f(void *a1)
{
    S_func_007637e0 *p = (S_func_007637e0 *)a1;
    p->f((int)this);
    func_00761660(*(void **)((char *)this + 8), a1);
}
