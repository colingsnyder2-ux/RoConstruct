// from server: 100% by king_originala
struct Control {
    int func_00460120(int);
    int func_00460c10(int, int);
    int func_004604a0(int, int);
};

struct Output {
    virtual void set(int);
};

struct CScriptEditor {
    int* func_004613d0();
    void func_00463f40(Output*);
};

void CScriptEditor::func_00463f40(Output* output)
{
    Control* control = reinterpret_cast<Control*>(func_004613d0());
    int value = control->func_00460120(1);
    value = control->func_00460c10(value, 1);
    value = control->func_004604a0(value, 1);
    output->set((~value) & 1);
}
