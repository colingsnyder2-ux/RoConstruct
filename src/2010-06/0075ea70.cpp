// from server: 44% by atomic.potato
extern "C" void __cdecl call_0078b890(void *, int);

struct S_func_00750ab0 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_00750ab0::f(int a1)
{
    m_x = 0;
}

struct CleanStage {
    char pad0[8];
    void *m_stage;
    void f(int a1);
};

void CleanStage::f(int a1)
{
    call_0078b890(m_stage, a1);
    ((S_func_00750ab0 *)a1)->f((int)this);
}
