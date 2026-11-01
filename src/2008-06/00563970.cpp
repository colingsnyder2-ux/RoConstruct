// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copyString;

struct String {
    char storage[28];
    String(const String& other) { copyString(this, other); }
    ~String();
};

struct Temporary {
    char storage[104];
    String value;
    Temporary();
    ~Temporary();
};

String __stdcall f()
{
    return Temporary().value;
}
