// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class Vector3 { public: float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Body { char pad[0x84]; Vector3 v; };
struct Link { char pad[0x34]; Body* body; };
class Part {
public:
    char pad[0x2c];
    Link* link;
    const Vector3& getVelocity() const;
};
const Vector3& Part::getVelocity() const
{
    if (Body* b = link->body)
        return b->v;
    static Vector3 zero(0.0f, 0.0f, 0.0f);
    return zero;
}
