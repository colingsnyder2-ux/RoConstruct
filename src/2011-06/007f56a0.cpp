// from server: 73% by atomic.potato
struct S_func_004e9330 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = (int)a1;
}

struct ContactStage {
    char pad0[8];
    void *m_stage;
    void process(void *a1);
};

extern "C" void func_004e9330(void *, int);
extern "C" void __stdcall func_007b4ac0(void *, void *);

void ContactStage::process(void *a1)
{
    func_004e9330(a1, (int)this);
    func_007b4ac0(m_stage, a1);
}
