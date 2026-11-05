// from server: 25% by atomic.potato
struct S_func_007b2f20
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

struct CleanStage
{
    char pad0[8];
    int m_stage;
    void f(int a1);
};

void CleanStage::f(int a1)
{
    S_func_007b2f20 *p = (S_func_007b2f20 *)a1;
    p->f((int)this);

    int *q = *(int **)((char *)this + 8);
    ((void (__thiscall *)(int *, int))0x007d9380)(q, a1);
}
