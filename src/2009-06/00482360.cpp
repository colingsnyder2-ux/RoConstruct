// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3 {
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    float dotProduct(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
};
struct Box { Vector3 mn, mx; };
struct NodeVisiter {
    char pad[0x1c];
    Vector3 normal;
    float nearDistance(const Box& b) const;
};
float NodeVisiter::nearDistance(const Box& b) const
{
Vector3 p(normal.x > 0 ? b.mn.x : b.mx.x, normal.y > 0 ? b.mn.y : b.mx.y, normal.z > 0 ? b.mn.z : b.mx.z); return normal.dotProduct(p);
}
