// from server: 100% by king_originala
struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Transform {
    Matrix rotation;
    float position[3];
};

struct Quaternion {
    float x, y, z, w;
    Quaternion(const Matrix&);
};

struct S {
    void clear();
    void prepare();
    void assign(const unsigned int*, int, int);
    void setRotation(float, float, float, float);
};

extern void __cdecl normalize(Matrix*);
extern void __cdecl setPosition(S*, const float*);
extern bool __cdecl isIdentity(const Matrix*);
extern unsigned int __cdecl encodeRotation(const Matrix*);

S* __cdecl convert(S* destination, const Transform* source)
{
    Transform value = {
        source->rotation,
        { source->position[0], source->position[1], source->position[2] }
    };

    normalize(&value.rotation);
    setPosition(destination, value.position);

    if (isIdentity(&value.rotation)) {
        destination->prepare();
        unsigned int encoded = encodeRotation(&value.rotation);
        destination->assign(&encoded, 6, 1);
    } else {
        destination->clear();
        Quaternion rotation(value.rotation);
        destination->setRotation(rotation.w, rotation.x, rotation.y, rotation.z);
    }

    return destination;
}
