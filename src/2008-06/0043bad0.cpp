// from server: 100% by king_originala
struct String
{
    char data[28];
    String(const String&);
    ~String();
};

extern void (__thiscall *stringCopy)(String*, const String&);
extern void (__thiscall *stringDestroy)(String*);

__forceinline String::String(const String& value)
{
    stringCopy(this, value);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct S
{
    S* f(int, int, int, String);
    void g(int, int, int, String);
};

S* S::f(int a, int b, int c, String value)
{
    g(a, b, c, value);
    return this;
}
