// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

struct Matrix {
    float data[9];
    Matrix(const Matrix&);
};

struct Frame {
    Matrix rotation;
    float x, y, z;
};

struct Tool {
    char pad[0x1cc];
    Matrix rotation;
    bool method_5ffb70(const Frame&);
    void method_5ffc00(const Vector&);
};

void Tool::method_5ffc00(const Vector& position) {
    Frame frame = { rotation, position.x, position.y, position.z };
    method_5ffb70(frame);
}
