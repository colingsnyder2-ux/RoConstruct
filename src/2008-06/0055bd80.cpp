// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    String(const char *);
    String(const String &);
    ~String();
};

extern String *(__thiscall *constructString)(String *, const char *);
extern String *(__thiscall *copyString)(String *, const String &);
extern void (__thiscall *destroyString)(String *);
extern String (__cdecl *concatenateString)(const String &, const char *);

inline String::String(const char *s)
{
    constructString(this, s);
}

inline String::String(const String &s)
{
    copyString(this, s);
}

inline String::~String()
{
    destroyString(this);
}

struct Name;
const Name &__cdecl getLocalScope();

struct Value {
    String text;
    const Name *scope;

    Value(const String &);
};

Value::Value(const String &s)
    : text(s), scope(&getLocalScope())
{
}

Value __cdecl makeValue(const char *path)
{
    String prefix("rbxasset://");
    return Value(concatenateString(prefix, path));
}
