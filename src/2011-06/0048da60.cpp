// from server: 57% by atomic.potato
struct S_func_0048aff0
{
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0048aff0::f()
{
    return &m_x;
}

struct CScriptEditor
{
    int f(int);
};

extern "C" int* __cdecl func_0048aff0();
extern "C" int func_0048a240(int, int, int);

int CScriptEditor::f(int x)
{
    int* p = func_0048aff0();
    int b = func_0048a240(0, (int)p, 1);
    return ((b != 0) ? 1 : 0);
}
