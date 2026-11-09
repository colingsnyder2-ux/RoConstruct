// from server: 59% by king_originala
struct String;

extern void (__thiscall *copyString)(String*, const String&);
extern void (__thiscall *destroyString)(String*);

struct String {
    unsigned char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    copyString(this, other);
}

inline String::~String()
{
    destroyString(this);
}

struct S {
    void cleanup(String first, int value, String second);
};

void __cdecl f(S* object, String first, int value, String second)
{
    object->cleanup(first, value, second);
}
