// from server: 52% by atomic.potato
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

struct CScintillaCtrl {
    char pad0[84];
    int m_a;
    int m_b;
    int f_0046d430(int);
    int f_0046df20(int, int);
    int f_0046d760(int, int, int);
};

int* CScriptEditor::f()
{
    S_func_0046e6f0* p = (S_func_0046e6f0*)0;
    int* r = p->f();
    CScintillaCtrl* c = (CScintillaCtrl*)r;
    int a = c->f_0046d430(1);
    int b = c->f_0046df20(a, 1);
    c->f_0046d760(b, 0, 1);
    return r;
}
