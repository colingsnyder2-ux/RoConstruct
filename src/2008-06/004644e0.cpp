// from server: 100% by king_originala
struct Control
{
    int canUndo(int direct);
    void undo(int direct);
};

struct CScriptEditor
{
    int* getControl();
    void func_004644e0(int unused);
};

void CScriptEditor::func_004644e0(int unused)
{
    Control* control = reinterpret_cast<Control*>(getControl());
    if (control->canUndo(1))
        control->undo(1);
}
