// from server: 100% by king_originala
struct String
{
    char storage[28];

    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern int __cdecl compare(const String &, const String &);

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String::~String()
{
    destroyString(this);
}

int __stdcall classify(String value)
{
    if (compare(value, String("exact")) == 0)
        return 0;

    bool matched = compare(value, String("close")) == 0;
    if (matched)
        return 1;
    return 2;
}
