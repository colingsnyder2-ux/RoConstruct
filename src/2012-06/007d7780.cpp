// from server: 45% by tester
struct Matrix3 {
    float m[9];
};

struct Vector3 {
    float x, y, z;
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
};

extern "C" void __fastcall sub_62C250(Matrix3* dest, const Matrix3* src);
extern "C" void __fastcall sub_7D7600(CoordinateFrame* self, const CoordinateFrame* other);

struct S {
    void f(CoordinateFrame* a, CoordinateFrame* b, CoordinateFrame* c);
};

void S::f(CoordinateFrame* a, CoordinateFrame* b, CoordinateFrame* c) {
    CoordinateFrame tmp;
    sub_62C250(&tmp.rotation, &a->rotation);
    tmp.translation = b->translation;
    sub_7D7600((CoordinateFrame*)((char*)this + 0x10), &tmp);
}
