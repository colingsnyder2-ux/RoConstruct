// from server: 86% by atomic.potato
struct CScriptEditor
{
    int GetValue();
    char padding[148];
    char field9c;
    char field9d;
    int field94;
};

int CScriptEditor::GetValue()
{
    if (field9c)
    {
        if (field9d)
            return 0xB90EDC;
    }
    return field94;
}
