// from server: 100% by king_originala
struct Control {
    int func_00460120(int direct);
    int func_00460c10(int position, int direct);
    void func_00460400(int position, int anchor, int direct);
};

struct CScriptEditor {
    int* func_004613d0();
    void func_00463f10();
};

void CScriptEditor::func_00463f10()
{
    Control* control = reinterpret_cast<Control*>(func_004613d0());
    int position = control->func_00460120(1);
    position = control->func_00460c10(position, 1);
    control->func_00460400(position, 0, 1);
}
