// from server: 56% by atomic.potato
struct S_func_0048aff0 {
    char pad0[88];
    int m_x;
    int* f();
};

struct CScriptEditor {
    int f();
};

int* S_func_0048aff0::f()
{
    return &m_x;
}

struct S_00489d00 {
    int f(int);
};

struct S_0048a830 {
    int f(int, int);
};

struct S_0048a070 {
    int f(int, int, int);
};

int CScriptEditor::f()
{
    S_func_0048aff0* p = (S_func_0048aff0*)this;
    int* q = p->f();
    int a = ((S_00489d00*)q)->f(1);
    int b = ((S_0048a830*)q)->f(a, 1);
    return ((S_0048a070*)q)->f(b, 0, 1);
}
