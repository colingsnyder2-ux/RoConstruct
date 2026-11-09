// from server: 100% by king_originala
struct Matrix
{
    float m[9];
};

struct Vector
{
    float x, y, z;
    Vector& operator=(const Vector& other);
};

inline Vector& Vector::operator=(const Vector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Transform
{
    Matrix rotation;
    Vector position;
};

namespace RBX
{
    class Instance
    {
    public:
        virtual ~Instance();
    };

    class Camera
    {
    public:
        virtual Transform getTransform() = 0;
    };

    class ICameraSubject : public virtual Camera
    {
    public:
        virtual ~ICameraSubject();
    };
}

struct S
{
    char padding[0x1a4];
    Transform transform;
    char gap[8];
    RBX::Instance* subject;

    void f();
};

void S::f()
{
    if (subject)
        transform = dynamic_cast<RBX::ICameraSubject*>(subject)->getTransform();
}
