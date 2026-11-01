// from server: 100% by king_originala
struct Matrix3 {
    float m[9];
};

struct Vector3 {
    float x, y, z;
};

struct Quaternion {
    float w, x, y, z;
};

struct Matrix4 {
    float m[16];
};

typedef void (__thiscall *FromRotationMatrixFn)(Quaternion*, const Matrix3&);
typedef void (__thiscall *MakeTransformFn)(Matrix4*, const Vector3&, const Vector3&, const Quaternion&);

extern FromRotationMatrixFn FromRotationMatrix;
extern MakeTransformFn makeTransform;

struct S {
    char padding[0x114];
    Matrix3 rotation;
    Vector3 position;

    void f(Matrix4*);
};

void S::f(Matrix4* output) {
    Quaternion q;
    q.w = 1.0f;
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    FromRotationMatrix(&q, rotation);

    Vector3 scale;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    makeTransform(output, position, scale, q);
}
