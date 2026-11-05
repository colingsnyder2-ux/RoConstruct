// from server: 53% by atomic.potato
struct S_func_0046e6f0 {
    char pad0[88];
    int m_x;
    int* f();
};

struct CScriptEditor {
    int* f();
};

int* S_func_0046e6f0::f()
{
    return &m_x;
}

extern "C" int* __stdcall sub_46d430(int);
extern "C" int* __stdcall sub_46df20(int, int);
extern "C" int* __stdcall sub_46d710(int, int, int);

int* CScriptEditor::f()
{
    S_func_0046e6f0* p = (S_func_0046e6f0*)0;
    int* r = p->f();
    int* a = (int*)sub_46d430(1);
    int* b = (int*)sub_46df20(1, (int)a);
    return (int*)sub_46d710(1, 0, (int)b);
}
