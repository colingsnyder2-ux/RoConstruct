// from server: 100% by king_originala
struct Color {
    float r, g, b, a;
};

struct Vector3 {
    float x, y, z;
};

struct S {
    Color color() const;
    Vector3 f() const;
};

Vector3 S::f() const {
    Color c = color();
    Vector3 result;
    result.x = c.r;
    result.y = c.g;
    result.z = c.b;
    return result;
}
