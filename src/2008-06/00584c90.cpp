// from server: 100% by colin
class type_info;

typedef bool (__thiscall *TypeInfoEqual)(const type_info*, const type_info&);
extern TypeInfoEqual typeInfoEqual;
extern type_info coordinateFrameType;

struct Descriptor {
    unsigned char reserved[8];
    const type_info* type;
};

struct Holder {
    virtual ~Holder();
    virtual void unused();
    virtual Holder* clone() const;

    static Holder* copy(const Holder*);
};

inline Holder* Holder::copy(const Holder* p)
{
    if (p)
        return p->clone();
    return 0;
}

struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;
};

struct Value {
    Descriptor* descriptor;
    Holder* object;

    Value(const Value&);
    ~Value();
    const Frame& convert() const;
    Frame get() const;
};

extern const Frame& __cdecl unboxFrame(Holder* const*);

inline Value::Value(const Value& source)
    : descriptor(source.descriptor)
{
    object = Holder::copy(source.object);
}

inline Value::~Value()
{
    if (object)
        delete object;
}

Frame Value::get() const
{
    const type_info* type = descriptor->type;
    if (typeInfoEqual(&coordinateFrameType, *type))
        return unboxFrame(&object);

    Value temporary(*this);
    return temporary.convert();
}
