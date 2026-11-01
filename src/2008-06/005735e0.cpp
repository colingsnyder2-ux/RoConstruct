// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Vector4 {
    float x, y, z, w;
};

extern float value_82f868;
extern float value_874d88;

extern const Vector3& __cdecl getVector3();
extern const Vector4& __cdecl getVector4();

struct S {
    char padding0[0x13c];
    float value13c;
    volatile float value140;
    char padding1[0x1c];
    volatile int value160;
    Vector4 value164;
    Vector4 value174;
    int value184;

    void initialize();
};

void S::initialize()
{
    value13c = value_82f868;
    value140 = value_874d88;
    value160 = 18;

    const volatile Vector3& v = getVector3();
    double x = v.x;
    double y = v.y;
    double z = v.z;
    value164.x = (float)x;
    value164.y = (float)y;
    value164.z = (float)z;
    value164.w = 1.0f;

    const Vector4& q = getVector4();
    value174.x = q.x;
    value174.y = q.y;
    value174.z = q.z;
    value174.w = q.w;

    value184 = 1;
}
