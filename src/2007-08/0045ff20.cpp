// from server: 100% by colin
struct CScriptEditor {
    void sub_63023e();
    CScriptEditor* sub_45d230();
    int sub_45cef0(int);
    int sub_45cec0(int);
    void func(int, int, int);
};

void CScriptEditor::func(int a, int b, int c)
{
    sub_63023e();
    CScriptEditor* p = sub_45d230();
    if (a == 0) {
        if (p->sub_45cef0(1) != 0) {
            p->sub_45cec0(1);
        }
    }
}
