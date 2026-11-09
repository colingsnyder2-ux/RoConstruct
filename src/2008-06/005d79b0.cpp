// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_242988241b41be39.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3& operator=(const Vector3& r) { x = r.x; y = r.y; z = r.z; return *this; }
};
class CoordinateFrame {
public:
    Vector3 pointToWorldSpace(const Vector3& v) const;
};
}
namespace RBX {
class Instance { public: char padding[0x1bc]; };
class PartInstance : public Instance {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class Workspace : public Instance {
public:
    static Workspace* findWorkspace(const Instance* context);
    static bool contextInWorkspace(const Instance* context);
};
class Humanoid : public Instance {
public:
    boost::shared_ptr<PartInstance> walkToPart;
    G3D::Vector3 walkToPoint;
    bool hasWalkToPoint(G3D::Vector3& worldPosition) const;
};
bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
{
    if (walkToPart != NULL && Workspace::findWorkspace(this) != NULL &&
        Workspace::contextInWorkspace(walkToPart.get())) {
        worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);
        return true;
    }
    return false;
}
}
