// from server: 100% by king_originala
struct Matrix {
    float data[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;
    Frame(const Matrix&, float, float, float);
    ~Frame();
};

struct S {
    void set(Frame);
};

__forceinline Frame::Frame(const Matrix& m, float a, float b, float c)
    : rotation(m), x(a), y(b), z(c)
{
}

void apply(S* object, Matrix rotation, float x, float y, float z)
{
    object->set(Frame(rotation, x, y, z));
}
