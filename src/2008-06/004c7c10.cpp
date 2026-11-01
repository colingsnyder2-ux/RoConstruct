// from server: 100% by king_originala
struct Matrix
{
    float values[9];
    Matrix(const Matrix &);
};

struct Transform
{
    Matrix matrix;
    float x, y, z;
};

struct Tail
{
    Tail(const Tail &);
};

struct S
{
    int value;
    Transform transform;
    Tail tail;

    S(const S &);
};

S::S(const S &other)
    : value(other.value),
      transform(other.transform),
      tail(other.tail)
{
}
