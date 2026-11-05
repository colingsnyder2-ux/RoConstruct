// from server: 100% by king_originala
struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;
};

struct Prefix {
    char padding[20];
};

struct Base {
    char data;
};

struct Owner : Prefix, Base {
};

struct GetSet {
    char padding[8];
    const Frame& (Owner::*getter)();

    Frame get(Base*);
};

Frame GetSet::get(Base* object)
{
    return (static_cast<Owner*>(object)->*getter)();
}
