// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
namespace RBX {
// 00598d20 returns true only when both embedded flags are zero.
// The inherited overlay names the second flag canCollide; target polarity is inverted.
bool PartInstance::getCanCollide() const {
    if (primitive.getDragging()) return false;
    if (primitive.getCanCollide()) return false;
    return true;
}
}
namespace RBX {
bool PartInstance::getAnchored() const { return primitive.getAnchor(); }
float PartInstance::getFriction() const { return primitive.getFriction(); }
Surfaces& PartInstance::getSurfaces() { return surfaces; }
}
#include "v8datamodel/Workspace.h"
namespace RBX {
void PartInstance::destroyJoints() {
    World* world = Workspace::getWorldIfInWorkspace(this);
    if (world) world->destroyJoints(&primitive);
}
}
namespace RBX {
bool PartInstance::getDragging() const { return primitive.getDragging(); }
float PartInstance::getElasticity() const { return primitive.getElasticity(); }
const G3D::Vector3& PartInstance::getPartSizeXml() const { return primitive.getGeometry()->getGridSize(); }
}
