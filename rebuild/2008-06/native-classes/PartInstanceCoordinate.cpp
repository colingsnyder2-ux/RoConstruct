// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-resize /I{headers}/part-embedded
// 2008 Body layout (native-headers/v8kernel/Body2008.h, pv +0x94, velocity +0xc4) for the velocity setters 0059da10 / 0059dad0.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi(
    "Position", "Data", &PartInstance::getTranslationUi, &PartInstance::setTranslationUi,
    Reflection::PropertyDescriptor::UI);
// 007f43f0 / 007f4450 (static init, 0x97632c / 0x976310): openrbx PartInstance.cpp prop_Velocity / prop_RotVelocity,
// flags 5 (STANDARD default), category "Data" 0x822490, getters 00599850 / 00599870.
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_Velocity(
    "Velocity", "Data", &PartInstance::getLinearVelocity, &PartInstance::setLinearVelocity,
    Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_RotVelocity(
    "RotVelocity", "Data", &PartInstance::getRotationalVelocity, &PartInstance::setRotationalVelocity,
    Reflection::PropertyDescriptor::STANDARD);

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
// 0059da10 (registry func_0059da10): openrbx PartInstance::setLinearVelocity; body +0x2c8 (embedded primitive's
// body), updatePV 00599360, Body::setVelocity 00614040, raisePropertyChanged(prop_Velocity 0x97632c).
void PartInstance::setLinearVelocity(const G3D::Vector3& set)
{
    Velocity vel = primitive.getBody()->getVelocity();
    if (vel.linear != set) {
        vel.linear = set;
        primitive.getBody()->setVelocity(vel);
        raisePropertyChanged(prop_Velocity);
    }
}
// 0059dad0 (registry func_0059dad0): openrbx PartInstance::setRotationalVelocity (prop_RotVelocity 0x976310).
void PartInstance::setRotationalVelocity(const G3D::Vector3& set)
{
    Velocity vel = primitive.getBody()->getVelocity();
    if (vel.rotational != set) {
        vel.rotational = set;
        primitive.getBody()->setVelocity(vel);
        raisePropertyChanged(prop_RotVelocity);
    }
}
}
