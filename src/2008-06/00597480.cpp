// from server: 100% by king_originala
struct Name;

struct String {
    unsigned char data[28];

    String(const String&);
    ~String();
    String& operator=(const String&);
};

extern void (__thiscall *copyString)(String*, const String&);
extern void (__thiscall *destroyString)(String*);
extern String& (__thiscall *assignString)(String*, const String&);
extern const Name& __cdecl getLocalScope();

inline String::String(const String& source)
{
    copyString(this, source);
}

inline String::~String()
{
    destroyString(this);
}

inline String& String::operator=(const String& source)
{
    return assignString(this, source);
}

struct Holder {
    String text;
    const Name* scope;
};

bool __cdecl reconstruct(const String& source, Holder* destination)
{
    Holder temporary = { source, &getLocalScope() };
    *destination = temporary;
    return true;
}
