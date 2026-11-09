// from server: 88% by atomic.potato
struct S_func_004e9330 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S_func_007b4240 {
    void f(int a1);
};

struct S_func_007efc60 {
    void f(int a1);
};

struct S_MechToAssemblyStage {
    char pad0[8];
    int m_x;
    void f(int a1);
};

void S_MechToAssemblyStage::f(int a1)
{
    ((S_func_004e9330*)a1)->f((int)this);
    ((S_func_007b4240*)m_x)->f(a1);
    ((S_func_007efc60*)(a1 + 8))->f(m_x);
}
