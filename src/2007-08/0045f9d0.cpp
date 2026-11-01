// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void*);

extern int dword_8BC0A0;
extern void* dword_8BC09C;

struct CScriptEditor {
    void sub_45F9D0();
};

void CScriptEditor::sub_45F9D0() {
    if (--dword_8BC0A0 == 0) {
        FreeLibrary(dword_8BC09C);
    }
    // tail call to 0x63005e
    extern void __fastcall sub_63005E(CScriptEditor*);
    sub_63005E(this);
}
