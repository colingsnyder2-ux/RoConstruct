// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

extern Vector3 __cdecl absolute(const Vector3&);
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

extern const float half;

struct Body {
    char reserved[0xB8];
    Vector3 position;
    const void* get();
    Vector3 getCenter() const;
};

struct Geometry {
    char reserved[4];
    Vector3 size;
};

struct Node {
    char reserved[0x9C];
    Geometry* geometry;
    Body* body;
};

struct Iterator {
    Node* current;
    int state;
    void advance();
};

struct S {
    char reserved[0x1C];
    Node* root;
    float f();
};

float S::f()
{
    float radius = 0.0f;
    Vector3 center = root->body->getCenter();
    Iterator it;
    it.current = root;
    it.state = 1;

    while (it.current) {
        Node* node = it.current;
        Body* body = node->body;
        body->get();

        Vector3 offset(
            body->position.x - center.x,
            body->position.y - center.y,
            body->position.z - center.z);
        Vector3 distance = absolute(offset);

        const Vector3& size = node->geometry->size;
        Vector3 scaled(size.x * half, size.y * half, size.z * half);
        Vector3 extent(
            scaled.x + distance.x,
            scaled.y + distance.y,
            scaled.z + distance.z);

        float candidate = (float)sqrt(
            extent.x * extent.x +
            extent.y * extent.y +
            extent.z * extent.z);

        const float& largest = radius < candidate ? candidate : radius;
        radius = largest;
        it.advance();
    }
    return radius;
}
