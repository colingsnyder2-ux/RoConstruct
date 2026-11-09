// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3&);
};

struct Transform {
    Matrix3 rotation;
    Vector3 position;
};

struct Item {
    char reserved[0x94];
    Transform transform;
    const void* get();
    void set(const Transform&);
};

struct Collection {
    Item** items;
    int count;
};

extern float angle;
extern void __cdecl adjust(Matrix3*, float);
extern bool __cdecl validate(Matrix3*);

struct S {
    char reserved[0x10];
    Collection* collection;
    void f(const Vector3&);
};

void S::f(const Vector3& offset)
{
    Collection* list = collection;
    for (int i = 0; i < list->count; ++i) {
        Item* item = list->items[i];
        item->get();
        Transform value = item->transform;
        value.position.x += offset.x;
        value.position.y += offset.y;
        value.position.z += offset.z;
        adjust(&value.rotation, angle);
        validate(&value.rotation);
        item->set(value);
    }
}
