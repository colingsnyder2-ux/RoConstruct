// from server: 100% by colin
struct Text;
extern const char* (__thiscall* text_data)(const Text*);

struct Text {
    int value;
    const char* c_str() const;
    ~Text() throw();

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

inline const char* Text::c_str() const
{
    return text_data(this);
}

inline Text::~Text() throw()
{
    destroyImport();
}

struct String;
extern void (__thiscall* string_construct)(String*, const char*);
extern void (__thiscall* string_destroy)(String*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

extern bool __cdecl parse_component(const String&, float*);

struct Vector {
    float x, y, z;
    Vector();
    Vector(float, float, float);
    float& operator[](int);
};

inline Vector::Vector()
{
}

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline float& Vector::operator[](int index)
{
    return (&x)[index];
}

struct Vector3ComponentItem {
    char padding[0x130];
    int component;
    Vector value;

    Text copy();
    Vector getValue();
};

Vector Vector3ComponentItem::getValue()
{
    Vector result;
    result.x = value.x;
    result.y = value.y;
    result.z = value.z;
    bool valid = parse_component(String(copy().c_str()),
                                 &result[component]);
    if (valid)
        return Vector(result.x, result.y, result.z);
    return Vector(value.x, value.y, value.z);
}
