// from server: 100% by tajop
// roc 2007-08 00460090  unit: CScriptEditor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460090

extern "C" __declspec(dllimport) int __stdcall MessageBeep(unsigned int uType);

struct CScriptEditor {
    int method_45d230();
    int method_45bf60(int);
    int method_45ca50(int, int);
    int method_45c370(int, int, int);
    int method_45c0d0(int, int);
    void run();
};

void CScriptEditor::run() {
    CScriptEditor* p = (CScriptEditor*)method_45d230();
    int a = p->method_45bf60(1);
    int b = p->method_45ca50(a, 1);
    int c = p->method_45c370(b - 1, 1, 1);
    if (c >= 0) {
        p->method_45c0d0(c, 1);
        return;
    }
    MessageBeep(0x10);
}
