// from server: 68% by atomic.potato
struct S_func_0048aff0 {
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0048aff0::f()
{
    return &m_x;
}

extern "C" int func_0048a240(int*, int, int);

struct CScriptEditor {
    int (**vftable)();
    int f(int);
};

int CScriptEditor::f(int a)
{
    S_func_0048aff0 *p;
    int b;

    p = (S_func_0048aff0 *)this;
    b = func_0048a240(p->f(), 2, 1) != 0;
    return ((int (__thiscall *)(CScriptEditor *, int))vftable[1])(this, b);
}
