// from server: 100% by atomic.potato
struct S_func_007d9f70
{
    void f(void *a1);
};

struct S_func_007b2f30
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct SleepStage
{
    void f(S_func_007b2f30 *a1);
};

void SleepStage::f(S_func_007b2f30 *a1)
{
    S_func_007d9f70 *p = (S_func_007d9f70 *)this;
    p->f(a1);
    a1->f((int)this);
}
