// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_16516c3533c1d74c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <vector>
#include <set>
namespace G3D {
class Vector2 {
public:
    float x, y;
};
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector2 xy() const;
};
class Rect2D {
public:
    Vector2 min, max;
    static Rect2D xywh(float x, float y, float w, float h);
    bool contains(const Vector2& v) const {
        return (v.x >= min.x) && (v.y >= min.y) && (v.x <= max.x) && (v.y <= max.y);
    }
};
class CoordinateFrame {
public:
    float rotation[9];
    Vector3 translation;
};
class GCamera {
public:
    Vector3 project(const Vector3& point, const Rect2D& viewport) const;
};
}
namespace RBX {
using namespace G3D;
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance {
public:
    virtual ~Instance();
    char padding[0x104];
    boost::shared_ptr<Instances> children;
    size_t numChildren() const { return children ? children->size() : 0; }
    Instance* getChild(size_t i) const { return (*children)[i].get(); }
};
class ILocation {
public:
    virtual const CoordinateFrame getLocation() const = 0;
};
class ISelectable3d {
public:
    virtual void s0();
};
class RenderDevice {
public:
    char padding[0x130];
    GCamera camera;
};
class IRenderableProvider {
public:
    virtual void p0();
    virtual RenderDevice* getRenderDevice();
};
class Workspace : public Instance {
public:
    char more[0x288 - 0x110];
    IRenderableProvider provider;
};
struct Vector2int16 { short x, y; };
struct UIEvent { char padding[0x10]; Vector2int16 mousePosition; };
bool __cdecl isLocked(Instance*);
class BoxSelectCommand {
public:
    char padding[0x18];
    Workspace* workspace;
    void select(std::set<Instance*>& result, const UIEvent& event, const Rect2D& box);
};
void BoxSelectCommand::select(std::set<Instance*>& result, const UIEvent& event, const Rect2D& box)
{
    RenderDevice* device = workspace->provider.getRenderDevice();
    Rect2D viewport = Rect2D::xywh(0, 0, event.mousePosition.x, event.mousePosition.y);
    for (size_t i = 0; i < workspace->numChildren(); ++i) {
        ILocation* location = dynamic_cast<ILocation*>(workspace->getChild(i));
        ISelectable3d* selectable = dynamic_cast<ISelectable3d*>(workspace->getChild(i));
        if (location && selectable) {
            Instance* child = workspace->getChild(i);
            if (!isLocked(child)) {
                Vector3 pos = location->getLocation().translation;
                Vector3 projected = device->camera.project(pos, viewport);
                if (box.contains(projected.xy()))
                    result.insert(child);
            }
        }
    }
}
}
