// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the vendor g3d-6.09 code was built with /fp:fast; the pragma below approximates it.
#pragma float_control(precise, off, push)

namespace {

struct Vector3 {
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    // INFERRED: float-wise copy (the original copies via the FPU, not integer moves).
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }

    // INFERRED: Vector3::zero() is inlined with its own static guard bit.
    static const Vector3& zero() {
        static const Vector3 v(0.0f, 0.0f, 0.0f);
        return v;
    }
};

struct AABB {
    Vector3 lo;
    Vector3 hi;
    AABB(const Vector3& l, const Vector3& h) : lo(l), hi(h) {}
};

}

// INFERRED: a static AABB built from two Vector3::zero() corners (24 bytes at 0x975550).
extern "C" const AABB* fn_00583860()
{
    static const AABB b(Vector3::zero(), Vector3::zero());
    return &b;
}

#pragma float_control(pop)
