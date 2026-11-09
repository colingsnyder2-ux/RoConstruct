// from server: 25% by Intel
struct Vector3 { float x, y, z; };
struct Matrix3x3 { float m[3][3]; };

extern "C" void __cdecl func_7bc350(Matrix3x3* out, const Vector3* v, float s);
extern "C" void __cdecl func_7bc3e0(Matrix3x3* out, float s, const Matrix3x3* m);

struct Clump {
    void __cdecl method(Vector3* out, const Vector3* v, const Matrix3x3* m, float s);
};

void Clump::method(Vector3* out, const Vector3* v, const Matrix3x3* m, float s)
{
    Matrix3x3 temp1;
    Matrix3x3 temp2;
    func_7bc350(&temp1, v, s);
    func_7bc3e0(&temp2, s, m);

    float vx = v->x;
    float vy = v->y;
    float vz = v->z;

    out->x = temp1.m[0][0] * vx + temp1.m[0][1] * vy + temp1.m[0][2] * vz;
    out->y = temp2.m[1][0] * vx + temp2.m[1][1] * vy + temp2.m[1][2] * vz;
    out->z = temp2.m[2][0] * vx + temp2.m[2][1] * vy + temp2.m[2][2] * vz;
}
