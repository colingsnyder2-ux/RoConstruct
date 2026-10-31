// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    static const Vector3& zero();
};
template<class T> class Array { public: T* data; int num; int numAllocated; };
}
namespace RBX {
enum NormalId { NORM_X = 0, NORM_UNDEFINED = 6 };
class Primitive;
class Instance;
class ContactManager;
class HitTestFilter { public: virtual ~HitTestFilter(); };
class PartByLocalCharacter : public HitTestFilter {
public:
    PartByLocalCharacter(Instance* i);
    ~PartByLocalCharacter();
    char pad[0x10];
};
class World { public: char pad[0xb0]; ContactManager* contactManager; ContactManager& getContactManager() { return *contactManager; } };
class Workspace { public: char pad[0x150]; World* world; World* getWorld() { return world; } };
class PartInstance { public: char pad[0x118]; Primitive* primitive; Primitive* getPrimitive() const { return primitive; } };
class RbxRay { public: G3D::Vector3 origin; G3D::Vector3 direction; };
class MouseCommand {
public:
    static PartInstance* getMousePart(const RbxRay& unitRay, ContactManager& contactManager, const Primitive* ignore, HitTestFilter* filter, G3D::Vector3& hitPoint, float maxSearch);
};
class RunDragger {
public:
    class SnapInfo {
    public:
        Primitive* snap;
        NormalId snapSurface;
        G3D::Vector3 hitWorld;
        G3D::Vector3 hitLocal;
        SnapInfo() : snap(0), snapSurface(NORM_UNDEFINED), hitWorld(G3D::Vector3::zero()), hitLocal(G3D::Vector3::zero()) {}
        void updateSurfaceFromHit();
    };
    char pad0[0x10];
    Workspace* workspace;
    Primitive* drag;
    char pad1[0x44 - 0x18];
    RbxRay mouseRay;
    bool notTried(Primitive* p, const G3D::Array<Primitive*>& triedSnap);
    bool adjacent(Primitive* a, Primitive* b);
    SnapInfo rayHitsPart(const G3D::Array<Primitive*>& triedSnap, bool forceAdjacent);
};
RunDragger::SnapInfo RunDragger::rayHitsPart(const G3D::Array<Primitive*>& triedSnap, bool forceAdjacent)
{
    SnapInfo answer;
    PartByLocalCharacter filter((Instance*)workspace);

    if (PartInstance* mousePart = MouseCommand::getMousePart(mouseRay, workspace->getWorld()->getContactManager(), drag, &filter, answer.hitWorld, 2048.0f))
    {
        Primitive* snap = mousePart->getPrimitive();
        answer.snap = snap;
        if (notTried(snap, triedSnap) && (!forceAdjacent || adjacent(snap, drag)))
        {
            answer.updateSurfaceFromHit();
            return answer;
        }
    }

    return SnapInfo();
}
}
