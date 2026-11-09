// from server: 100% by king_originala
struct Matrix
{
    float values[9];
    Matrix(float, float, float, float, float, float, float, float, float);
};

const Matrix& getMatrix()
{
    static Matrix value(
        0.0f, -1.0f, 0.0f,
        1.0f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f
    );
    return value;
}
