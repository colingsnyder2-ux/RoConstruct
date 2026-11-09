// from server: 100% by king_originala
struct Base {
    float data[9];
    Base(const Base&);
};

struct Camera {
    Base base;
    float x, y, z;

    Camera(const Camera&);
};

inline Camera::Camera(const Camera& other)
    : base(other.base), x(other.x), y(other.y), z(other.z)
{
}

struct __multiple_inheritance Object;
typedef Camera (Object::*Getter)();

struct S {
    unsigned char padding[8];
    Getter getter;

    Camera get(void* object);
};

Camera S::get(void* object)
{
    Object* target = object
        ? reinterpret_cast<Object*>(static_cast<char*>(object) - 20)
        : 0;
    return (target->*getter)();
}
