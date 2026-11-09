// from server: 27% by colin
struct Vector3 {
    float x, y, z;
};

struct Sphere {
    Vector3 center;
    float radius;
    Sphere();
    Sphere(const Sphere& other);
    virtual ~Sphere();
};

struct SphereHolder {
    char pad0[0x6c];
    Vector3 v6c;
    char pad78[0x8];
    Sphere sphere80;
    char pad90;
    unsigned char flag90;
    char pad91[0x3];
    float f94;
    char pad98[0x268];
    char buf300[0xf8];
    char buf3f8[8];
    SphereHolder(const SphereHolder& other);
    ~SphereHolder();
};

SphereHolder::SphereHolder(const SphereHolder& other) {
    sphere80 = other.sphere80;
    flag90 = other.flag90;
    f94 = other.f94;
    v6c = other.v6c;
    for (int i = 0; i < 0xf8; ++i) buf300[i] = other.buf300[i];
    for (int i = 0; i < 8; ++i) buf3f8[i] = other.buf3f8[i];
}

SphereHolder::~SphereHolder() {
}
