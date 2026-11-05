// from server: 100% by atomic.potato
struct CScintillaCtrl {
    int method_a(int a, int b);
    int method_b(int a, int b, int c);
};

struct CScriptEditor {
    char pad[88];
    CScintillaCtrl m_ctrl;
    __declspec(noinline) CScintillaCtrl* get_ctrl();
    void func();
};

CScintillaCtrl* CScriptEditor::get_ctrl()
{
    return &m_ctrl;
}

void CScriptEditor::func()
{
    CScintillaCtrl* p = get_ctrl();
    int r = p->method_a(0, 1);
    if (r) {
        p->method_b(0, 0, 1);
    } else {
        p->method_b(0, 0x20, 1);
    }
}
