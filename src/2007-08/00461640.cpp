// from server: 100% by colin
struct CScriptEditor {
    char pad[0x100];
    void sub_461270();
    void sub_460650();
    void func_00461640(int, int, int);
};

void CScriptEditor::func_00461640(int a, int b, int c)
{
    int id = b;
    if (id == 0x8c1274) {
        ((CScriptEditor*)((char*)this - 0xf0))->sub_461270();
    } else if (id == 0x8c14bc) {
        ((CScriptEditor*)((char*)this - 0xf0))->sub_460650();
    }
}
