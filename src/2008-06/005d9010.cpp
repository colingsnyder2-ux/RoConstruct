// from server: 100% by king_originala
struct String
{
    char data[28];

    String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);

__forceinline String::String(const char* text)
{
    string_construct(this, text);
}

__forceinline String::~String()
{
    string_destroy(this);
}

struct Part
{
    Part* find(const String&);
};

struct S
{
    Part* f();
};

extern "C" Part* __cdecl sub_005d8b10();

Part* S::f()
{
    Part* p = sub_005d8b10();
    return p ? p->find(String("Right Shoulder")) : 0;
}
