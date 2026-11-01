// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3& value);
};

inline Vector3& Vector3::operator=(const Vector3& value)
{
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

struct Ray {
    Vector3 origin;
    Vector3 direction;
    virtual ~Ray();
};

inline Ray::~Ray()
{
}

struct Transform {
    Ray transformRay(const Ray& ray) const;
    Vector3 transformPoint(const Vector3& point) const;
};

struct Source {
    char reserved[0x94];
    Transform transform;
    const void* get();
};

struct Provider {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual bool intersect(const Ray& ray, Vector3& point, float& limit) = 0;
};

struct Primitive {
    char reserved[0x9c];
    Provider* provider;
    Source* source;
    bool func_005e7f20(const Ray& ray, Vector3& point, float& limit);
};

bool Primitive::func_005e7f20(const Ray& ray, Vector3& point, float& limit)
{
    Source* current = source;
    current->get();
    Ray localRay = current->transform.transformRay(ray);
    Vector3 localPoint = { 0.0f, 0.0f, 0.0f };

    if (provider->intersect(localRay, localPoint, limit)) {
        current = source;
        current->get();
        point = current->transform.transformPoint(localPoint);
        return true;
    }
    return false;
}
