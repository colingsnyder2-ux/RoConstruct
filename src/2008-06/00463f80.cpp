// from server: 100% by king_originala
struct Control {
    int func_00460120(int);
    int func_00460c10(int, int);
    void func_00460450(int, int, int);
};

struct CScriptEditor {
    int* func_004613d0();
    void func_00463f80();
};

void CScriptEditor::func_00463f80()
{
    Control* control = reinterpret_cast<Control*>(func_004613d0());
    int position = control->func_00460120(1);
    int line = control->func_00460c10(position, 1);
    control->func_00460450(line, 0, 1);
}
