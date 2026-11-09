// from server: 100% by king_originala
class type_info;
extern bool (__thiscall *type_equal)(const type_info*, const type_info&);

class type_info
{
public:
    bool operator==(const type_info&) const;
};

inline bool type_info::operator==(const type_info& other) const
{
    return type_equal(this, other);
}

extern void (__thiscall *string_destroy)(void*);

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    string_destroy(this);
}

struct Value
{
    char data[0x20];
    Value(const String&);
    Value(const Value&);
    ~Value();
};

inline Value::~Value()
{
    string_destroy(this);
}

struct Object
{
    virtual ~Object();
};

struct Holder
{
    Object* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder&);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Holder& other)
{
    if (this != &other)
    {
        Object* replacement = value;
        Object* saved = other.value;
        value = saved;
        other.value = replacement;
    }
}

struct Descriptor
{
    void* reserved[2];
    const type_info* type;
};

extern const type_info reference_type;
extern String stringify(const Holder&);
extern Descriptor* get_descriptor();

struct S
{
    Descriptor* descriptor;
    Holder holder;
    void finish();
    void f();
};

void S::f()
{
    if (reference_type == *descriptor->type)
    {
        Holder(Value(stringify(holder))).swap(holder);
        descriptor = get_descriptor();
    }
    finish();
}
