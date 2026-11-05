// from server: 100% by colin
#pragma float_control(precise, off, push)

struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c);
    Vector3(const Vector3& v);
    Vector3 operator*(float s) const;
    Vector3& operator*=(float s);
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

inline Vector3 Vector3::operator*(float s) const
{
    return Vector3(x * s, y * s, z * s);
}

inline Vector3& Vector3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

struct Matrix3 {
    float m[3][3];

    Matrix3(const Matrix3&);
    Vector3 column(int) const;
    Matrix3 operator*(const Matrix3&) const;
    static Matrix3 fromAxisAngle(const Vector3&, float);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
};

struct Object {
    const Frame& getFrame() const;
    void setFrame(const Frame&);
};

extern int __cdecl closestAxis(const Vector3&, const Frame&);
extern const float rotationAngle;

void __cdecl rotateFrame(Object* object, const Matrix3& reference)
{
    Frame frame = object->getFrame();
    Vector3 direction = reference.column(0);
    int face = closestAxis(direction, frame);
    int column = face % 3;

    Vector3 axis(frame.rotation.m[0][column],
                frame.rotation.m[1][column],
                frame.rotation.m[2][column]);
    axis *= float(1 - 2 * (face / 3));

    Matrix3 rotation = Matrix3::fromAxisAngle(axis, rotationAngle);
    frame.rotation = rotation * frame.rotation;
    object->setFrame(frame);
}

#pragma float_control(pop)