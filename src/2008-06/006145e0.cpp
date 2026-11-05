// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Matrix {
    float elements[9];
    Matrix(const Matrix& value);
};

struct Source {
    float angle();
    const Matrix& rotation();
};

extern Matrix __cdecl multiply(const Matrix&, const Matrix&);
extern void __cdecl calculate(Vector3*, const Vector3*, const void*,
                              const Matrix*, float);

struct Link {
    char reserved0[0x28];
    Source* source;
    char reserved1[0x3c];
    Matrix localRotation;
    float localAngle;
    char reserved2[4];
    Matrix offsetRotation;

    const void* get();
    Vector3* getCofmInBody(Vector3* result);
    Vector3* evaluate(Vector3* result, const void* value);
};

Vector3* Link::evaluate(Vector3* result, const void* value)
{
    float angle = source ? source->angle() : localAngle;
    get();

    Matrix rotation(source ? source->rotation() : localRotation);
    Matrix transformed = multiply(rotation, offsetRotation);
    Vector3 center;

    calculate(result, getCofmInBody(&center), value, &transformed, angle);
    return result;
}
