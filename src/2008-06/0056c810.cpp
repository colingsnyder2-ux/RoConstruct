// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copyString;

struct String {
    unsigned char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& source)
{
    copyString(this, source);
}

struct Value {
    String name;
    int value;

    Value(const Value&);
};

inline Value::Value(const Value& source)
    : name(source.name), value(source.value)
{
}

struct Base {
    virtual ~Base();
};

struct S : Base {
    Value data;

    S(const Value&);
    virtual ~S();
};

S::S(const Value& source)
    : data(source)
{
}
