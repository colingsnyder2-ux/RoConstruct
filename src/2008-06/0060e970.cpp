// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(float, float, float);
    Vector3& operator=(const Vector3&);
    static const Vector3& zero();
    static const Vector3& up();
};

inline Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
inline Vector3::Vector3(float a, float b, float c) : x(a), y(b), z(c) {}

inline Vector3& Vector3::operator=(const Vector3& value) {
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

inline const Vector3& Vector3::zero() {
    static const Vector3 value;
    return value;
}

inline const Vector3& Vector3::up() {
    static const Vector3 value(0.0f, 1.0f, 0.0f);
    return value;
}

struct Ray {
    Vector3 origin;
    Vector3 direction;
    virtual ~Ray();
};

inline Ray::~Ray() {}

struct Plane {
    Vector3 normal;
    float distance;
    Plane(const Vector3&, const Vector3&);
    virtual ~Plane();
};

inline Plane::~Plane() {}

struct Contact {
    int query(const Ray&, const void*, int, Vector3*, const void*);
};

extern const unsigned char queryData;
extern Ray __cdecl makeRay(const void*);
extern bool __cdecl intersect(const Ray&, const Plane&, Vector3*);
extern Vector3 __cdecl normalize(const Vector3&);

bool __cdecl calculate(Contact* contact, const void* source,
                       const void* geometry, Vector3* result) {
    Ray ray = makeRay(source);
    if (!contact->query(ray, geometry, 0, result, &queryData)) {
        if (!intersect(ray, Plane(Vector3::up(), Vector3::zero()), result)) {
            *result = Vector3::zero();
            return false;
        }
    }
    *result = normalize(*result);
    return true;
}
