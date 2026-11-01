// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class PVInstance;
class Workspace {
public:
    static Workspace* findWorkspace(const Instance* i);
    void moveToPoint(PVInstance* pv, G3D::Vector3 point, bool flag);
};
class PVInstance : public Instance {
public:
    void moveToPoint(G3D::Vector3 point);
};
void PVInstance::moveToPoint(G3D::Vector3 point)
{
    Workspace* workspace = Workspace::findWorkspace(this);
    if (workspace)
        workspace->moveToPoint(this, point, true);
}
}
