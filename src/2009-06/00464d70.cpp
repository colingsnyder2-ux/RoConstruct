// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Control {
    int query(int, bool);
    void update(int, int, bool);
};

struct CScriptEditor {
    int* control();
    void func_00464100();
};

void CScriptEditor::func_00464100()
{
    Control* p = reinterpret_cast<Control*>(control());
    if (p->query(1, true))
        p->update(1, 0, true);
    else
        p->update(1, 16, true);
}