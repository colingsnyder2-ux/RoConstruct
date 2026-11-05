// from server: 100% by king_originala
struct Matrix3 {
    float m[9];
};

struct Transform {
    Matrix3 rotation;
    float x, y, z;

    const Transform& get() const;
};

struct Part {
    Transform convert(const Transform& value);
};

extern char instanceType;
extern char partType;

extern "C" void* __cdecl runtimeCast(
    void* object, long displacement, void* sourceType,
    void* destinationType, int isReference);

struct Feature {
    char padding[0x104];
    void* object;

    Transform localTransform();
    bool f(Transform& result);
};

bool Feature::f(Transform& result)
{
    Part* part = static_cast<Part*>(
        runtimeCast(object, 0, &instanceType, &partType, 0));

    if (part) {
        Transform local = localTransform();
        const Transform& value = part->convert(local).get();

        result.rotation = value.rotation;
        result.x = value.x;
        result.y = value.y;
        result.z = value.z;
        return true;
    }

    return false;
}
