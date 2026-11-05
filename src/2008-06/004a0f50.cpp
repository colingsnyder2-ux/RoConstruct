// from server: 54% by king_originala
struct String;

typedef void (__thiscall *StringCopy)(String*, const String&);
typedef void (__thiscall *StringDestroy)(String*);

extern StringCopy stringCopy;
extern StringDestroy stringDestroy;

struct String {
    char storage[28];
    String(const String&);
    ~String();
};

__forceinline String::String(const String& other)
{
    stringCopy(this, other);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct Bound {
    void invoke(int*, String, int*, String);
};

struct S {
    char padding[16];
    Bound bound;
    void f(int, String, int, String);
};

void S::f(int first, String firstText, int second, String secondText)
{
    bound.invoke(&first, firstText, &second, secondText);
}
