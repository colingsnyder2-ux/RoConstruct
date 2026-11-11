// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-resize /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PartInstanceCoordinate | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9a058f62 | roc native-status --write
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi(
    "Position", "Data", &PartInstance::getTranslationUi, &PartInstance::setTranslationUi,
    Reflection::PropertyDescriptor::UI);

void PartInstance::setCoordinateFrame(const G3D::CoordinateFrame& value)
{
    Primitive* storage = &primitive;
    const G3D::CoordinateFrame& current = storage->getCoordinateFrame();
    const G3D::CoordinateFrame* source = &value;
    if (*source != current) {
        G3D::CoordinateFrame newValue = *source;
        Math::orthonormalizeIfNecessary(newValue.rotation);
        if (newValue != storage->getCoordinateFrame()) {
            storage->setCoordinateFrame(newValue);
            PersistentPart.setDirty();
            onExtentsChanged();
        }
        raisePropertyChanged(prop_CFrame);
        raisePropertyChanged(prop_PositionUi);
    }
}
void PartInstance::setTranslationUi(const G3D::Vector3& value)
{
    G3D::CoordinateFrame current = primitive.getCoordinateFrame();
    if (current.translation != value) {
        current.translation = value;
        World* world = Workspace::getWorldIfInWorkspace(this);
        if (world) world->destroyJoints(&primitive);
        setCoordinateFrame(current);
        safeMove();
        world = Workspace::getWorldIfInWorkspace(this);
        if (world) world->createJoints(&primitive);
    }
}
}
