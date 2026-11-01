// from server: 100% by colin
// from server: 93% by king_originala
struct type_info {};

extern const type_info colorType;
extern bool (__thiscall *compareType)(const type_info*, const type_info&);

struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c);
    Vector3(const Vector3& other);
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector3::Vector3(const Vector3& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct TypeRecord {
    char padding[8];
    const type_info* info;
};

struct Payload {
    virtual ~Payload();
    virtual void unused();
    virtual Payload* clone();
};

inline Payload* copyPayload(Payload* source)
{
    if (source)
        return source->clone();
    return 0;
}

struct Value;

struct Temporary {
    TypeRecord* type;
    Payload* payload;

    Temporary(const Value& value);
    ~Temporary();
    const Vector3& convert();
};

extern const Vector3& __cdecl extractVector(Payload* const*);

struct Value {
    TypeRecord* type;
    Payload* payload;

    Vector3 get();
};

inline Temporary::Temporary(const Value& value)
{
    type = value.type;
    payload = copyPayload(value.payload);
}

inline Temporary::~Temporary()
{
    if (payload)
        delete payload;
}

Vector3 Value::get()
{
    const type_info* t = type->info;
    if (compareType(&colorType, *t)) {
        const Vector3& v = extractVector(&payload);
        return Vector3(v.x, v.y, v.z);
    }

    Temporary temporary(*this);
    return temporary.convert();
}
