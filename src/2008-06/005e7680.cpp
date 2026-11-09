// from server: 100% by king_originala
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
    unsigned char padding[156];
    ScaleData* data;

    Result* __thiscall f(Result*, const void*);
};

Result* S::f(Result* result, const void* input)
{
    const Vector* scale = &data->scale;
    const Vector* value = getVector(input);

    Vector product;
    product.x = value->x * scale->x;
    product.y = value->y * scale->y;
    product.z = value->z * scale->z;

    result->assign(*getMatrix(input));
    result->translation.x = product.x;
    result->translation.y = product.y;
    result->translation.z = product.z;
    return result;
}
