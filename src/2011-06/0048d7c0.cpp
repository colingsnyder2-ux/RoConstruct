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

struct CScintillaCtrl {
    int sub_00489d00(int);
    int sub_0048a830(int, int);
    int sub_0048a020(int, int, int);
};

int CScriptEditor::f()
{
    S_func_0048aff0* p = (S_func_0048aff0*)0;
    CScintillaCtrl* esi = (CScintillaCtrl*)p->f();
    int v = esi->sub_00489d00(1);
    v = esi->sub_0048a830(v, 1);
    return esi->sub_0048a020(v, 0, 1);
}
