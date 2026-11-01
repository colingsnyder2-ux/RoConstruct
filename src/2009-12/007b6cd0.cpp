// from server: 100% by atomic.potato
struct S_func_007d94e0
{
    char pad0[8];
    void f(void* a1);
};

struct S_func_007b2f30
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct CleanStage
{
    char pad0[8];
    S_func_007d94e0* m_obj;
    void f(int a1);
};

void CleanStage::f(int a1)
{
    m_obj->f((void*)a1);
    ((S_func_007b2f30*)a1)->f((int)this);
}
