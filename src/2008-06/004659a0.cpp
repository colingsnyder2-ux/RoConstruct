// from server: 100% by king_originala
extern const char defaultText[];
extern const char* (__thiscall* string_c_str)(const void*);

struct TextTarget
{
    void setText(const char*);
};

struct Document
{
    char padding[0x110];
    char text[1];
};

struct CScriptEditor
{
    char padding[0x144];
    Document* document;

    TextTarget* getTextTarget();
    void refresh();
    int func_004659a0(unsigned int, unsigned int);
};

int CScriptEditor::func_004659a0(unsigned int, unsigned int)
{
    if (getTextTarget())
    {
        if (!document)
            getTextTarget()->setText(defaultText);
        else
            getTextTarget()->setText(string_c_str(document->text));
    }
    refresh();
    return 0;
}
