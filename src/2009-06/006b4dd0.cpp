// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    static const Vector3& zero() { static Vector3 v(0.0f, 0.0f, 0.0f); return v; }
};
template<class T> class Array {
    T* data;
    int num;
public:
    int size() const { return num; }
};
}
namespace RBX {
class Primitive;
class ContactManager;
G3D::Vector3 moveUp(const G3D::Vector3& v, float amount);
class Dragger {
public:
    static void initMove(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& move);
    static bool intersecting(const G3D::Array<Primitive*>& primitives, ContactManager& cm);
    static void moveDown(const G3D::Array<Primitive*>& primitives, G3D::Vector3& move, ContactManager& cm);
    static void moveUpOut(const G3D::Array<Primitive*>& primitives, G3D::Vector3& move, ContactManager& cm);
    static G3D::Vector3 safeMoveYDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager);
};
G3D::Vector3 Dragger::safeMoveYDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryMove, ContactManager& contactManager)
{
    if (primitives.size() == 0) {
        return G3D::Vector3::zero();
    }
    G3D::Vector3 answer = moveUp(tryMove, 0.1f);
    initMove(primitives, answer);
    if (intersecting(primitives, contactManager)) {
        moveUpOut(primitives, answer, contactManager);
    } else {
        moveDown(primitives, answer, contactManager);
    }
    return answer;
}
}
