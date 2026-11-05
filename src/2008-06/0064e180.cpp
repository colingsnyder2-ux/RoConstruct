// from server: 100% by king_originala
struct String {
    unsigned char data[28];
};

typedef String& (__thiscall *StringAssign)(String*, const String&);
extern StringAssign assignString;

struct Value {
    String text;
    int value;
};

struct S {
    unsigned char padding[0x144];
    Value field;
    void set(const Value& source);
};

void S::set(const Value& source)
{
    Value* destination = &field;
    assignString(&destination->text, source.text);
    destination->value = source.value;
}
