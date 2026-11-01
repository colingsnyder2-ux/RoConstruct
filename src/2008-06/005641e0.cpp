// from server: 100% by colin
struct TypeInfo {};
extern TypeInfo double_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo &type() const;
    virtual Holder *clone() const;
};

struct Any {
    Holder *content;
    Any(const Any &other);
};

inline Any::Any(const Any &other)
    : content(other.content ? other.content->clone() : 0)
{
}

extern const double *__cdecl double_value(const Any *);

struct Type {
    unsigned char padding[8];
    const TypeInfo *info;
};

struct S {
    Type *descriptor;
    Any value;

    S(const S &other);
    ~S();
    const double &convert();
    double get() const;
};

inline S::S(const S &other)
    : descriptor(other.descriptor), value(other.value)
{
}

inline S::~S()
{
    if (value.content)
        delete value.content;
}

double S::get() const
{
    const TypeInfo *typeInfo = descriptor->info;
    if (type_equal(&double_type, *typeInfo))
        return *double_value(&value);

    S temporary(*this);
    return temporary.convert();
}
