// from server: 100% by colin
struct TypeInfo;
extern TypeInfo boolType;
extern bool (__thiscall *equalType)(const TypeInfo *, const TypeInfo &);

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo &type() const;
    virtual Holder *clone() const;
};

struct Descriptor {
    unsigned char padding[8];
    const TypeInfo *type;
};

extern bool *__cdecl getStoredBool(Holder **);

inline Holder *cloneHolder(Holder *holder)
{
    if (holder)
        return holder->clone();
    return 0;
}

struct Value {
    Descriptor *descriptor;
    Holder *holder;

    Value(const Value &other);
    ~Value();
    bool *convert();
};

inline Value::Value(const Value &other)
    : descriptor(other.descriptor),
      holder(cloneHolder(other.holder))
{
}

inline Value::~Value()
{
    if (holder)
        delete holder;
}

struct FactoryProduct : Value {
    bool get();
};

bool FactoryProduct::get()
{
    const TypeInfo *typeInfo = descriptor->type;
    if (equalType(&boolType, *typeInfo))
        return *getStoredBool(&holder);

    Value temporary(*this);
    return *temporary.convert();
}
