// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)

struct Matrix3 {
    float values[9];
};

struct Vector3 {
    float values[3];
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
};

extern bool __cdecl checkMatrix(const Matrix3&);
extern bool __cdecl checkVector(const Vector3&);

bool __cdecl checkFrame(const Frame& value)
{
    return checkVector(value.translation) && checkMatrix(value.rotation);
}