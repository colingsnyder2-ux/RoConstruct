// from server: 74% by tajop
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);

inline float sqrtf_g3d(float v) { return (float)sqrt(v); }

struct Vector2 {
    float x, y;
    float length() const { return sqrtf_g3d(x * x + y * y); }
};

struct Vector3 {
    float x, y, z;
    Vector2 xy() const;
};

struct SphereBuilder {
    static void squareCircle(Vector3& v);
};

void SphereBuilder::squareCircle(Vector3& v)
{
    float ay = (float)fabs(v.y);
    float ax = (float)fabs(v.x);
    float s;
    if (ax <= ay) {
        if (0.0f == v.y) {
            s = 0.0f;
        } else {
            s = ay / v.xy().length();
        }
    } else {
        if (0.0f == v.x) {
            s = 0.0f;
        } else {
            s = ax / v.xy().length();
        }
    }
    v.x = v.x * s;
    v.y = v.y * s;
}
