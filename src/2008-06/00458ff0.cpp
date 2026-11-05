// from server: 67% by king_originala
struct String
{
    char data[28];

    String(const char*);
    String(const String&);
    ~String();
};

extern void (__thiscall* stringConstructor)(String*, const char*);

inline String::String(const char* text)
{
    stringConstructor(this, text);
}

double __cdecl G2_func_005083d0();

struct Verb
{
    char data[12];

    Verb(void*, String);
    virtual ~Verb();
};

struct InsertModelFromRobloxVerb : Verb
{
    double timestamp;

    InsertModelFromRobloxVerb(void*);
    virtual ~InsertModelFromRobloxVerb();
};

InsertModelFromRobloxVerb::InsertModelFromRobloxVerb(void* context)
    : Verb(context, String("TogglePlayMode"))
{
    timestamp = G2_func_005083d0();
}
