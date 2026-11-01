// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Name;
const Name* __cdecl declareName(const char*);
extern bool crashOnDeclare;
void crash();
extern const char typeTag[];

class Descriptor {
public:
    Descriptor(const char* n) : name(declareName(n))
    {
        if (crashOnDeclare)
            crash();
    }
    virtual ~Descriptor();
    const Name* name;
};

class Type : public Descriptor {
public:
    Type(const char* name, const char* tagName, int);
    virtual ~Type();
    const char* tag;
    const Name* tagName;
    bool a;
    bool b;
};

Type::Type(const char* name, const char* tn, int)
    : Descriptor(name), tag(typeTag), tagName(declareName(tn)), a(false), b(false)
{
}
