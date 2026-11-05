// from server: 100% by king_originala
struct String;

extern void (__thiscall *stringConstruct)(String *);
extern void (__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned char data[28];

    String() { stringConstruct(this); }
    String(const String &other) { stringCopy(this, other); }
    ~String() { stringDestroy(this); }
};

struct Name;
extern const Name &__cdecl getLocalScope();

struct Value {
    String text;
    const Name *scope;

    Value() : scope(&getLocalScope()) {}
};

struct Reader {
    bool read(Value &);
};

struct Input {
    unsigned char padding[16];
    Reader reader;
    bool empty();
};

struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void *, const Value &) = 0;
};

struct S {
    unsigned char padding[24];
    Accessor *accessor;

    void f(void *, Input *, int);
};

void S::f(void *object, Input *input, int)
{
    if (!input->empty()) {
        Value value;
        if (input->reader.read(value)) {
            Value copy(value);
            accessor->set(object, copy);
        }
    }
}
