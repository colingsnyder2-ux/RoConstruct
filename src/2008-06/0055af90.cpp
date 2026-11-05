// from server: 100% by king_originala
struct String {
    char storage[28];
};

struct Property;
extern Property changedProperty;

extern bool (__cdecl *stringNotEqual)(const String&, const String&);
extern String& (__thiscall *stringAssign)(String*, const String&);

struct S {
    char padding[0x110];
    String value;

    void notify(const Property&);
    void setValue(const String&);
};

void S::setValue(const String& input)
{
    if (stringNotEqual(value, input)) {
        stringAssign(&value, input);
        notify(changedProperty);
    }
}
