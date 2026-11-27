// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-resize /I{headers}/part-embedded
// 2008 Body layout (native-headers/v8kernel/Body2008.h, pv +0x94, velocity +0xc4) for the velocity setters 0059da10 / 0059dad0.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
// 007f4330 (static init, 0x976198): "CFrame" ("Data"), flags 5 (STANDARD), getter 00598cb0, setter 0059d8a0.
const Reflection::PropDescriptor<PartInstance, G3D::CoordinateFrame> PartInstance::prop_CFrame(
    "CFrame", "Data", &PartInstance::getCoordinateFrame, &PartInstance::setCoordinateFrame,
    Reflection::PropertyDescriptor::STANDARD);
Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi(
    "Position", "Data", &PartInstance::getTranslationUi, &PartInstance::setTranslationUi,
    Reflection::PropertyDescriptor::UI);
// 007f43f0 / 007f4450 (static init, 0x97632c / 0x976310): openrbx PartInstance.cpp prop_Velocity / prop_RotVelocity,
// flags 5 (STANDARD default), category "Data" 0x822490, getters 00599850 / 00599870.
Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_Velocity(
    "Velocity", "Data", &PartInstance::getLinearVelocity, &PartInstance::setLinearVelocity,
    Reflection::PropertyDescriptor::STANDARD);
Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_RotVelocity(
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
// Body getters through the embedded primitive's body (+0x2c8), each an updatePV 00599360 call then a field
// address/value of the 2008 Body (Body2008.h: mass +0x8c, pv +0x94; pv.position.translation +0xb8, pv.velocity
// linear +0xc4 / rotational +0xd0). Identities: 00599830 is the getter of prop_PositionUi (static init 007f4390
// stores it), 00599850 / 00599870 the getters of prop_Velocity / prop_RotVelocity (007f43f0 / 007f4450); 00598cc0
// is the float() BoundFuncDesc target of the static init 007f4530 (descriptor 0x976288; openrbx PartInstance
// "GetMass" -> getMass). Registry placeholders func_00599830/50/70, func_00598cc0.
// 00598cc0
float PartInstance::getMass()
{
    return primitive.getBody()->getMass();
}
// 00599830
const G3D::Vector3& PartInstance::getTranslationUi() const
{
    return primitive.getBody()->getPos();
}
// 00599850
const G3D::Vector3& PartInstance::getLinearVelocity() const
{
    return primitive.getBody()->getVelocity().linear;
}
// 00599870
const G3D::Vector3& PartInstance::getRotationalVelocity() const
{
    return primitive.getBody()->getVelocity().rotational;
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
