// from server: 45% by atomic.potato
struct S_func_004e9330 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = (int)a1;
}

struct CleanStage {
    char pad0[8];
    int m_stage;
    void f(void *a1);
};

extern "C" void __cdecl call_007ee2f0(int, void *);

void CleanStage::f(void *a1)
{
    S_func_004e9330 *p = (S_func_004e9330 *)a1;
    p->f((int)this);
    call_007ee2f0(m_stage, a1);
}
