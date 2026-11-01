// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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