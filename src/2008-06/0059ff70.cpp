// from server: 100% by colin
#pragma float_control(precise, off)

extern char property;

struct Vector3 {
    float x, y, z;
};

struct S {
    char pad[0x180];
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
