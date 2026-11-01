// from server: 100% by king_originala
struct Control {
    int func_004610b0(int);
    int func_00461080(int);
};

struct CScriptEditor {
    void func_006a0c68();
    int* func_004613d0();
    void func_00463ed0(unsigned int, unsigned int, unsigned int);
};

void CScriptEditor::func_00463ed0(unsigned int key, unsigned int, unsigned int)
{
    func_006a0c68();
    Control* control = reinterpret_cast<Control*>(func_004613d0());
    if (key == 0 && control->func_004610b0(1))
        control->func_00461080(1);
}
