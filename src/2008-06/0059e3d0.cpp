// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct PackedValue {
    unsigned int value;
    PackedValue();
};

extern PackedValue __cdecl convert(Vector3);
extern unsigned char propertyA;
extern unsigned char propertyB;

struct Settings {
    unsigned char padding[0x1e4];
    unsigned int value;

    void notify(void*);
    void setValue(const Vector3&);
};

void Settings::setValue(const Vector3& v)
{
    unsigned int converted = convert(v).value;
    if (converted != value) {
        value = converted;
        notify(&propertyA);
        notify(&propertyB);
    }
}
