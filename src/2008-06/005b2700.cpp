// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

struct Rotation {
    float data[9];
    Rotation(const Rotation&);
};

struct Frame {
    Rotation rotation;
    Vector position;
};

struct S {
    char padding[0x158];
    Rotation rotation;

    void set(const Frame&);
    void f(const Vector&);
};

void S::f(const Vector& position)
{
    Frame frame = { rotation, { position.x, position.y, position.z } };
    set(frame);
}
