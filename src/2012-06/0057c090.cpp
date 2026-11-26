// from server: 100% by Xemicl
// copied from an identical function in another client (function ?function@ns_ROCX000001@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX000001 {
struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Transform {
    Matrix rotation;
    float position[3];
};

struct S {
    Transform get();
};

void __cdecl consume(void*, const Transform&);

void __cdecl function(S* object, void* destination)
{
    consume(destination, object->get());
}
}
