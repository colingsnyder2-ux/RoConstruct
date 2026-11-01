// from server: 100% by king_originala
struct Value {
    unsigned char data[28];
    unsigned long extra;

    Value &operator=(const Value &);
};

extern bool __cdecl different(const Value *, const Value *);
extern Value &(__thiscall *assignString)(Value *, const Value *);
extern int valueProperty;
extern int shapeProperty;

inline Value &Value::operator=(const Value &v)
{
    assignString(this, &v);
    extra = v.extra;
    return *this;
}

struct S {
    unsigned char padding[0x130];
    int shape;
    unsigned char gap[12];
    Value value;

    void notify(const void *);
    void setValue(const Value &);
};

void S::setValue(const Value &v)
{
    if (different(&value, &v)) {
        value = v;
        notify(&valueProperty);
        if (shape != 5) {
            shape = 5;
            notify(&shapeProperty);
        }
    }
}
