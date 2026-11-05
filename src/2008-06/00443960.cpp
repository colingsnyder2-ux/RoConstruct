// from server: 100% by king_originala
struct TypeInfo {};
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern TypeInfo string_type;

struct Metadata {
    unsigned char padding[8];
    const TypeInfo* type;
};

struct Value {
    virtual ~Value();
    virtual void reserved();
    virtual Value* clone();
};

extern int* __cdecl access_value(Value**);

struct S {
    Metadata* metadata;
    Value* value;

    S(const S&);
    ~S();
    int* convert();
    int f();
};

inline S::S(const S& other)
{
    *reinterpret_cast<Metadata* volatile*>(&metadata) = other.metadata;

    Value* p = other.value;
    Value* copy;
    if (p)
        copy = p->clone();
    else
        copy = 0;
    value = copy;
}

inline S::~S()
{
    delete value;
}

int S::f()
{
    const TypeInfo* type =
        *reinterpret_cast<const TypeInfo* volatile*>(&metadata->type);
    if (type_equal(&string_type, *type))
        return *access_value(&value);

    S temporary(*this);
    return *temporary.convert();
}
