// from server: 100% by colin
#pragma float_control(precise, off)

struct Vector3 {
    static float x, y, z;
    Vector3();
};

float Vector3::x;
float Vector3::y;
float Vector3::z;

inline Vector3::Vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

struct BodyVelocity {
    char padding[0x148];
    float x, y, z;
    bool isNonzero();
};

bool BodyVelocity::isNonzero()
{
    static Vector3 zero;
    return x != zero.x || y != zero.y || z != zero.z;
}
