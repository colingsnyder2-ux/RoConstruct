// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// from server: 100% by king_originala
// roc 2008-06 005e7680  unit: RBX::Ball  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7680
//

struct Vector {
    float x, y, z;
};

struct Matrix {
    float data[9];
};

struct Result {
    Matrix rotation;
    Vector translation;
    Result& __thiscall assign(const Matrix&);
};

extern "C" const Vector* __cdecl getVector(const void*);
extern "C" const Matrix* __cdecl getMatrix(const void*);

struct ScaleData {
    unsigned char padding[4];
    Vector scale;
};

struct S {
    unsigned char padding[0xe0];
    ScaleData* data;

    Result* __thiscall f(Result*, const void*);
};

Result* S::f(Result* result, const void* input)
{
    const Vector* scale = &data->scale;
    const Vector* value = getVector(input);

    Vector half;
    half.x = value->x * 0.5f;
    half.y = value->y * 0.5f;
    half.z = value->z * 0.5f;
    Vector product;
    product.x = half.x * scale->x;
    product.y = half.y * scale->y;
    product.z = half.z * scale->z;

    result->assign(*getMatrix(input));
    result->translation.x = product.x;
    result->translation.y = product.y;
    result->translation.z = product.z;
    return result;
}
