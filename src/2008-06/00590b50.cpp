// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
};
}
namespace RBX {
class PartInstance;
template<class T> class WeakPtr { T* px; void* pn; };
class PartArray {
    char pad[0xc];
    WeakPtr<PartInstance>* first;
    WeakPtr<PartInstance>* last;
public:
    unsigned int size() const { return last - first; }
};
class Extents {
public:
    G3D::Vector3 low;
    G3D::Vector3 high;
    G3D::Vector3 bottomCenter() const
    {
        G3D::Vector3 v = (this->low + this->high) * 0.5f;
        v.y = low.y;
        return v;
    }
};
class DragUtilities { public: static Extents computeExtents(const PartArray& partArray); };
class Dragger { public: static G3D::Vector3 toGrid(const G3D::Vector3& v); };
enum MoveType { MOVE_DROP = 0 };
class RootInstance {
public:
    G3D::Vector3 computeIdeInsertPoint(const Extents& extents);
    void moveSafe(PartArray& partArray, G3D::Vector3 move, MoveType moveType);
    void moveToIdeInsertPoint(PartArray& partArray);
};
void RootInstance::moveToIdeInsertPoint(PartArray& partArray)
{
    if (partArray.size() > 0)
    {
        Extents extents = DragUtilities::computeExtents(partArray);
        G3D::Vector3 insertPoint = computeIdeInsertPoint(extents);
        insertPoint = insertPoint - extents.bottomCenter();
        G3D::Vector3 moveToInsert = Dragger::toGrid(insertPoint);
        moveSafe(partArray, moveToInsert, MOVE_DROP);
    }
}
}
