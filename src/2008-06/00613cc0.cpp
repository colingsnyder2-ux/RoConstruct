// from server: 100% by king_originala
struct Matrix {
    float value[9];
    Matrix(const Matrix&);
};

struct Vector {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector position;
};

extern const Matrix* __cdecl rotate(void*, const Matrix*, float);
extern void __cdecl apply(const Frame*, void*, void*);

struct S {
    char padding0[8];
    Matrix basis;
    Vector position;
    char padding1[0x30];
    char destination[0x64];
    float angle;

    void update(void*);
};

void S::update(void* argument)
{
    float storage[9];
    Frame frame = {
        *rotate(storage, &basis, angle),
        { position.x, position.y, position.z }
    };
    apply(&frame, destination, argument);
}
