// from server: 100% by king_originala
struct Control {
    void setReadOnly(int value, int direct);
};

struct EditorBase {
    char padding[88];
    int value;
    int* control();
};

struct CScriptEditor {
    char padding[65];
    bool readOnly;
    bool editable;
    void f(int unused, int value);
};

void CScriptEditor::f(int unused, int value)
{
    readOnly = value != 0;
    int state = (readOnly || !editable) ? 1 : 0;
    reinterpret_cast<Control*>(
        reinterpret_cast<EditorBase*>(
            reinterpret_cast<char*>(this) - 276)->control()
    )->setReadOnly(state, 1);
}
