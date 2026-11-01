// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void func_00464170();
};

void CScriptEditor::func_00464170()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(0, true))
        p->update(0, 0, true);
    else
        p->update(0, 32, true);
}