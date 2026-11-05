// from server: 100% by colin
struct CScriptEditor {
    char pad[0x39];
    bool field_39;
    bool field_3a;
    int sub_45D230(int, int);
    int sub_45CAD0();
    int func_0045F920(int, int);
};

int CScriptEditor::func_0045F920(int a, int b)
{
    bool v = (b != 0);
    field_39 = v;
    int r;
    if (!v && field_3a != v) {
        r = 0;
    } else {
        r = 1;
    }
    CScriptEditor* p = (CScriptEditor*)((char*)this - 0x10c);
    int t = p->sub_45D230(r, 1);
    return ((CScriptEditor*)t)->sub_45CAD0();
}
