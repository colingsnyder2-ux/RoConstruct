// from server: 100% by king_originala
struct Matrix {
    unsigned int data[9];
    Matrix(const Matrix&);
};

extern const Matrix& __cdecl getMatrix();

struct RotateSelectionVerb {
    Matrix f();
};

Matrix RotateSelectionVerb::f() {
    return getMatrix();
}
