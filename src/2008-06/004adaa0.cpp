// from server: 100% by king_originala
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
