// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[9];
};

struct Quaternion {
    float w, x, y, z;
};

struct Matrix4 {
    float m[16];
};

extern void (__thiscall *FromRotationMatrix)(Quaternion *, const Matrix3 *);
extern Quaternion *(__thiscall *MultiplyQuaternion)(
    const Quaternion *, Quaternion *, const Quaternion *);
extern void (__thiscall *MakeTransform)(
    Matrix4 *, const Vector3 *, const Vector3 *, const Quaternion *);

struct S {
    char padding[0x114];
    Matrix3 rotation;
    Vector3 translation;

    void f(Matrix4 *, const Vector3 *, const Vector3 *, const Quaternion *);
};

void S::f(Matrix4 *output, const Vector3 *position,
          const Vector3 *scale, const Quaternion *orientation)
{
    struct Locals {
        union {
            Quaternion temporary;
            Vector3 translated;
        } scratch;
        Quaternion q;
    } local;

    local.q.w = 1.0f;
    local.q.x = 0.0f;
    local.q.y = 0.0f;
    local.q.z = 0.0f;

    FromRotationMatrix(&local.q, &rotation);

    Quaternion *result =
        MultiplyQuaternion(&local.q, &local.scratch.temporary, orientation);
    local.q.w = result->w;
    local.q.x = result->x;
    local.q.y = result->y;
    local.q.z = result->z;

    local.scratch.translated.x =
        static_cast<const volatile Vector3 *>(position)->x + translation.x;
    local.scratch.translated.y = translation.y + position->y;
    local.scratch.translated.z = translation.z + position->z;

    MakeTransform(output, &local.scratch.translated, scale, &local.q);
}
