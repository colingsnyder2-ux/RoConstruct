// from server: 70% by atomic.potato
struct CScriptEditor {
    char pad[0x54];
    CScriptEditor* field_54;
    void func_004a0af0(int, int, int);
};

extern "C" void __stdcall func_004029f0(int, CScriptEditor*);
extern "C" void __stdcall func_0049e320(int, int, int);

void CScriptEditor::func_004a0af0(int a, int b, int c)
{
    func_0049e320(a, b, c);
    if (a) {
        CScriptEditor* p = field_54;
        func_004029f0(1, p->field_54);
    }
}
