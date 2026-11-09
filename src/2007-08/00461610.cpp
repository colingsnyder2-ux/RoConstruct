// from server: 58% by colin
struct CScriptEditor {
    void sub_461510(int, int);
    void f(int, int, int);
};

void CScriptEditor::f(int a, int b, int c)
{
    if (b == 0x8c1274 || b == 0x8c14bc) {
        int tmp[2];
        tmp[0] = b;
        tmp[1] = c;
        sub_461510(a, (int)tmp);
    }
}
