// from server: 100% by king_originala
extern const char event_00975770[];
extern const char event_00973d54[];

struct CScriptEditor {
    void func_00465550();
    void func_00464540();
    void func_004659f0(int, const void*, int);
};

void CScriptEditor::func_004659f0(int, const void* event, int)
{
    if (event == event_00975770) {
        reinterpret_cast<CScriptEditor*>(
            reinterpret_cast<char*>(this) - 0xF0)->func_00465550();
        return;
    }

    if (event == event_00973d54) {
        reinterpret_cast<CScriptEditor*>(
            reinterpret_cast<char*>(this) - 0xF0)->func_00464540();
    }
}
