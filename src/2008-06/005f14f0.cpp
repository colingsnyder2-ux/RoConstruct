// from server: 100% by colin
// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
//

extern float defaultFirst;
extern float defaultSecond;

struct Value {
    int kind;
    float first;
    float second;
    Value();
};

inline Value::Value()
    : kind(0), first(defaultFirst), second(defaultSecond)
{
}

struct Values {
    char padding[0xd0];
    Value* entries[1];
    const Value& get(int) const;
    void set(int, const Value*);
};

inline const Value& Values::get(int index) const
{
    if (entries[index])
        return *entries[index];
    static Value empty;
    return empty;
}

struct Property { void* descriptor(); };
struct PartInstance {
    char padding[0x228];
    Values values;
    void setShouldRender(int);
    Property* f(int);
    void notify(void*);
};

struct FaceInstance {
    PartInstance* part;
    int face;
    void setSecond(float);
};

void FaceInstance::setSecond(float second)
{
    const Value& ref = part->values.get(face);
    Value value = ref;
    if (value.first != second) {
        value.first = second;
        part->values.set(face, &value);
        part->setShouldRender(face);
        part->notify(part->f(face)->descriptor());
    }
}
