// from server: 100% by king_originala
#pragma float_control(precise, off)

extern char property;

struct Vector3 {
    float x, y, z;
};

struct S {
    char pad[0x134];
    Vector3 value;
    void setValue(const Vector3& v);
    void notify(const char* p);
};

void S::setValue(const Vector3& v)
{
    if (value.x != v.x || value.y != v.y || value.z != v.z) {
        value.x = v.x;
        value.y = v.y;
        value.z = v.z;
        notify(&property);
    }
}
