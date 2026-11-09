// from server: 100% by king_originala
struct Matrix {
    float elements[9];
};

struct Transform {
    Matrix rotation;
    float x, y, z;
    Transform& operator=(const Transform& value);
};

inline Transform& Transform::operator=(const Transform& value)
{
    rotation = value.rotation;
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

struct S {
    char padding[0x114];
    Transform transform;
    void setTransform(const Transform& value);
};

void S::setTransform(const Transform& value)
{
    transform = value;
}
