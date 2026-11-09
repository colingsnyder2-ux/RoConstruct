// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);
extern int __cdecl compare(const String&, const String&);

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

int __stdcall mapColor(String value)
{
    if (compare(value, String("ball")) == 0)
        return 0;
    if (compare(value, String("block")) == 0)
        return 1;
    if (compare(value, String("cylinder")) == 0)
        return 2;
    return 999;
}
