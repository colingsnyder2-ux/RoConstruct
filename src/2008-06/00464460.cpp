// from server: 100% by king_originala
extern "C" int (__cdecl* _stricmp)(const char*, const char*);
extern const char comparisonText[];
extern const char replacementText[];

struct TextRange
{
    int start;
    int end;
    char* text;
};

struct Control
{
    int selectionStart(int direct);
    int selectionEnd(int direct);
    int getTextRange(TextRange* range, int direct);
    int replaceSelection(int unused, const char* text, int direct);
};

struct CScriptEditor
{
    Control* getControl();
    void func_00464460(int unused);
};

void CScriptEditor::func_00464460(int unused)
{
    Control* control = getControl();
    int start = control->selectionStart(1);
    int end = control->selectionEnd(1);

    if (start == end && start > 12)
    {
        TextRange range;
        char text[16];

        range.end = end - 1;
        range.start = start - 13;
        range.text = text;
        control->getTextRange(&range, 1);

        if (_stricmp(text, comparisonText) == 0)
            control->replaceSelection(0, replacementText, 1);
    }
}
