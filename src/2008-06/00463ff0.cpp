// from server: 100% by king_originala
extern "C" int (__stdcall *MessageBeep)(unsigned int);

struct EditorControl {
    int GetCurrentPos(int direct);
    int LineFromPosition(int position, int direct);
    int FindColumn(int line, int column, int direct);
    void GotoPos(int position, int direct);
};

struct CScriptEditor {
    EditorControl* GetControl();
    void MoveToNextLine();
};

void CScriptEditor::MoveToNextLine()
{
    EditorControl* control = GetControl();
    int position = control->GetCurrentPos(1);
    int line = control->LineFromPosition(position, 1);
    position = control->FindColumn(line + 1, 1, 1);
    if (position >= 0)
        control->GotoPos(position, 1);
    else
        MessageBeep(0x10);
}
