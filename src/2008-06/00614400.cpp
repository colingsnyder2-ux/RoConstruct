// from server: 100% by king_originala
struct Matrix {
    float values[9];
    Matrix& operator=(const Matrix&);
};

struct Vector {
    float x, y, z;
};

struct Frame {
    Matrix matrix;
    Vector position;
};

struct State {
    Matrix matrix;
    Vector position;
    Vector linearVelocity;
    Vector angularVelocity;
};

struct S {
    char reserved[0xC4];
    Vector linearVelocity;
    Vector angularVelocity;

    const void* get();
    void setState(const State&);
    void f(const Frame&);
};

void S::f(const Frame& frame)
{
    get();

    State state;
    state.matrix = frame.matrix;
    state.position.x = frame.position.x;
    state.position.y = frame.position.y;
    state.position.z = frame.position.z;
    state.linearVelocity.x = linearVelocity.x;
    state.linearVelocity.y = linearVelocity.y;
    state.linearVelocity.z = linearVelocity.z;
    state.angularVelocity.x = angularVelocity.x;
    state.angularVelocity.y = angularVelocity.y;
    state.angularVelocity.z = angularVelocity.z;

    setState(state);
}
