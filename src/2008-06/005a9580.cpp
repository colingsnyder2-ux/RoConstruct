// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Matrix {
    float elements[9];
    bool equal(const Matrix& other) const;
};

struct Transform {
    Matrix rotation;
    float x, y, z;
};

extern void* typeDescriptor;

extern "C" Transform* __cdecl getTransform(void* state, int index, void* type);
extern "C" void __cdecl pushBoolean(void* state, int value);

int __cdecl compareTransforms(void* state)
{
    Transform* a = getTransform(state, 2, typeDescriptor);
    Transform* b = getTransform(state, 1, typeDescriptor);

    int result = b->x == a->x &&
                 b->y == a->y &&
                 b->z == a->z &&
                 b->rotation.equal(a->rotation);

    pushBoolean(state, static_cast<unsigned char>(result));
    return 1;
}
