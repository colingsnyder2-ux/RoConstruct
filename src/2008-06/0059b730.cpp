// from server: 100% by colin
// from server: 93% by king_originala
class type_info {};

extern const type_info vectorType;
extern bool (__thiscall *compareType)(const type_info*, const type_info&);

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

__forceinline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct Placeholder;

struct PlaceholderTable {
    void (__thiscall *destroy)(Placeholder*, unsigned int);
    const type_info& (__thiscall *type)(const Placeholder*);
    Placeholder* (__thiscall *clone)(const Placeholder*);
};

struct Placeholder {
    PlaceholderTable* table;
    static Placeholder* copy(const Placeholder*);
};

__forceinline Placeholder* Placeholder::copy(const Placeholder* p)
{
    if (p)
        return p->table->clone(p);
    return 0;
}

struct Type {
    unsigned long padding[2];
    const type_info* info;
};

extern const Vector3& __cdecl extractVector(Placeholder* const*);

struct Value {
    Type* descriptor;
    Placeholder* content;

    Value(const Value&);
    ~Value();
    const Vector3& convert();
    Vector3 get();
};

__forceinline Value::Value(const Value& v)
    : descriptor(v.descriptor), content(Placeholder::copy(v.content))
{
}

__forceinline Value::~Value()
{
    Placeholder* p = content;
    if (p)
        p->table->destroy(p, 1);
}

Vector3 Value::get()
{
    const type_info* t = descriptor->info;
    if (compareType(&vectorType, *t))
        return extractVector(&content);

    Value temporary(*this);
    return temporary.convert();
}
