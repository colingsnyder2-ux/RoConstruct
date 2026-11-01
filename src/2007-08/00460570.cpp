// from server: 100% by colin
struct CScriptEditor {
    int sub_45CEF0(int);
    void sub_45CEC0(int);

    void sub_460570(int);
};

extern "C" void* __cdecl sub_45D230();

void CScriptEditor::sub_460570(int)
{
    CScriptEditor* p = (CScriptEditor*)sub_45D230();
    if (p->sub_45CEF0(1)) {
        p->sub_45CEC0(1);
    }
}
