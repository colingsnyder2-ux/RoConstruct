// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid.h"

namespace RBX {
namespace HUMAN {

// 006431b0
// PARKED near-miss (195/195 bytes, only the store offset differs): the target stores Body +0x30 (2008 Body
// canThrottle, native-headers/v8kernel/Body2008.h); this unit reaches the donor v8kernel/Body.h through the
// part-embedded PartInstance/Primitive, whose canThrottle is at +0x24. Needs a Body2008 setCanThrottle reachable from
// a PartInstance unit (header proposal).
void HumanoidState::setLimbFlag(bool value)
{
    if (!humanoid)
        return;
    if (humanoid->getHead())
        humanoid->getHead()->getPrimitive()->getBody()->setCanThrottle(value);
    if (humanoid->getTorso())
        humanoid->getTorso()->getPrimitive()->getBody()->setCanThrottle(value);
    if (humanoid->getRightArm())
        humanoid->getRightArm()->getPrimitive()->getBody()->setCanThrottle(value);
    if (humanoid->getLeftArm())
        humanoid->getLeftArm()->getPrimitive()->getBody()->setCanThrottle(value);
    if (humanoid->getRightLeg())
        humanoid->getRightLeg()->getPrimitive()->getBody()->setCanThrottle(value);
    if (humanoid->getLeftLeg())
        humanoid->getLeftLeg()->getPrimitive()->getBody()->setCanThrottle(value);
}

// 006432e0
HitTestFilter::Result HumanoidState::filterResult(const Primitive* testMe) const
{
    const Primitive* torso = humanoid->getTorsoPrimitive();
    HitTestFilter::Result result = HitTestFilter::INCLUDE_PRIM;
    if (testMe->getDragging() || testMe->getCanSleep()
        || (torso && torso->getAssembly() == testMe->getAssembly()))
        result = HitTestFilter::IGNORE_PRIM;
    return result;
}

// 00643360
float HumanoidState::getDesiredAltitude()
{
    float altitude = floorTouchInWorld.y;
    if (humanoid->getTorsoPrimitive())
        altitude += humanoid->getTorsoPrimitive()->getGeometry()->getGridSize().y * 0.5f;
    if (humanoid->getLeftLegPrimitive())
        return humanoid->getLeftLegPrimitive()->getGeometry()->getGridSize().y + altitude;
    if (humanoid->getRightLegPrimitive())
        return humanoid->getRightLegPrimitive()->getGeometry()->getGridSize().y + altitude;
    return altitude;
}

// 006444f0
// PARKED (header proposal): humanoid/Humanoid.h declares Humanoid::getPrimitives (005d9db0) private and places
// world at +0x218 (the 2008 Humanoid has it at +0x21c, Humanoid2008.h), while Humanoid2008.h declares neither
// getPrimitives nor the primitive getters 005d90a0..005d9100. A trial with the access opened compiled 390 bytes against
// 374: world offset 0x218, and the early `!world` return emitted its own epilogue (target branches to the shared one).
#if 0
bool HumanoidState::onFloorStep()
{
    World* world = humanoid->getWorld();
    if (!world)
        return false;
    std::vector<Primitive*> primitives;
    humanoid->getPrimitives(primitives);
    std::set<Primitive*> ignore(primitives.begin(), primitives.end());
    if (humanoid->getTorsoPrimitive()
        && world->getContactManager().intersectingOthers(humanoid->getTorsoPrimitive(), ignore, 0.0f))
        return true;
    if (humanoid->getHeadPrimitive()
        && world->getContactManager().intersectingOthers(humanoid->getHeadPrimitive(), ignore, 0.0f))
        return true;
    return false;
}
#endif

}
}
