// from server: 100% by king_originala
struct String {
    unsigned char data[28];
};

struct Value {
    String text;
    unsigned long extra;
};

extern bool __cdecl differs(const Value *, const Value *);
extern String & (__thiscall *assignString)(String *, const String &);

extern const char valueProperty[];
extern const char kindProperty[];

struct S {
    unsigned char padding0[0x130];
    int kind;
    unsigned char padding1[0x2C];
    Value value;

    void changed(const void *);
    void setValue(const Value *);
};

void S::setValue(const Value *source)
{
    Value *destination = &value;
    if (differs(destination, source)) {
        assignString(&destination->text, source->text);
        destination->extra = source->extra;
        changed(valueProperty);
        if (kind != 5) {
            kind = 5;
            changed(kindProperty);
        }
    }
}
