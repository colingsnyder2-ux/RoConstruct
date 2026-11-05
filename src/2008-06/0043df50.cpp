// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct CStr {
    __declspec(dllimport) CStr(const char*);
    __declspec(dllimport) CStr(const CStr&);
    __declspec(dllimport) ~CStr();
    char* p;
};

struct Source;

struct First {
    virtual ~First();
    char padding[0x1c];
};

struct Second {
    virtual ~Second();
    char padding[0xd8];
    int flag;
    char tail[0xc];
};

struct Base : First, Second {
    Base(const char*, int, int);
    ~Base();
    int GetFlags();
    void SetFlags(int);
    void SetValue(CStr);
};

struct Link {
    virtual ~Link();
    char padding[0x1c];
    Link(Source*, int);
};

struct Item : Base, Link {
    Source* source;
    Item(Source*, int);
    virtual ~Item();
};

struct ScriptItem : Item {
    ScriptItem(Source*, int);
    virtual ~ScriptItem();
};

ScriptItem::ScriptItem(Source* input, int option)
    : Item(input, option)
{
    SetFlags(GetFlags() | 2);
    SetFlags(GetFlags() & ~1);
    SetValue("(Script)");
}
