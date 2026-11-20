// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Batch 28: the 2008 Body path (native-headers/v8kernel/Body2008.h, canThrottle +0x30) for setLimbFlag 006431b0.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/GeometryService.h"   // getPartsTouchingExtents 0062db60 (00644a30)
#include "AppDraw/Draw.h"                   // Draw::selectionBox(const Part&, Adorn*, const Color4&) 00676e00
#include "RbxGraphics/Adorn.h"
#include <G3D/AABox.h>

namespace RBX {
namespace HUMAN {

// 006431b0
// Stores Body +0x30 (2008 Body canThrottle): this unit defines NATIVE_PRIMITIVE_NATIVE_BODY, so the part-embedded
// Primitive reaches native-headers/v8kernel/Body2008.h and its inline setCanThrottle (batch 28).
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

// INFERRED: the donor v8tree/Instance.h defines isDescendentOf inline (first level `ancestor == parent`, then the
// parent's recursion); 00644a30 inlines that first level and calls the out-of-line copy 00422ae0 on the parent, while
// core v8tree/Instance.h only declares it out of line. File-local copy of the donor inline's shape (batch 25 rule 3).
static inline bool donorIsDescendentOf(const Instance* instance, const Instance* ancestor)
{
	Instance* thisParent = instance->getParent();
	if (ancestor == thisParent)
		return true;
	if (thisParent)
		return thisParent->isDescendentOf(ancestor);
	else
		return false;
}

// 00644a30 (585 bytes, thiscall `ret 4`, analog name; registry placeholder func_00644a30; only caller findClimbable
// 00644c80, same original HumanoidState unit 00643xxx..006454xx). Decoded from the target (no donor body): torso Body
// 005d9160 coordinate frame (updatePV 00599360, pv +0x94), ServiceProvider::find<GeometryService>(humanoid) 006449e0,
// lookVector (getColumn 00513240 times -1), Extents center -/+ (1, 2.7, 1) / (1, 0, 1), array14 resize(0, false)
// 0062d9e0, GeometryService::getPartsTouchingExtents 0062db60; any part outside the character (humanoid parent +0x104,
// isDescendentOf 00422ae0) returns true after Draw::selectionBox 00676e00 (Color3 red 005148b0); otherwise, with an
// adorn, setObjectToWorldMatrix (slot 14) and box (slot 16) with Color4(1, 0.2, 0.2, 0.5) / Color4::zero 007baf10.
// PARKED (batch 28, 585/585 bytes, first divergence insn 83 00644b18): instructions 1..82 match (torso frame, lookVector,
// extents, the GeometryService query); the target walks the array with a hoisted data pointer (`mov edi, [edi]` once,
// `add edi, 4`, part kept in [esp+0x10]) where the candidate reloads data each iteration (`mov ecx, [edi]; mov eax,
// [ecx+ebx*4]`), then register choices in the adorn tails. Rejected: `i < array14.size()` (diverges at insn 78, size
// reloaded), a `parts = array14.getCArray()` local (data loaded before the size test, insn 78). Kept: the `count` local.
bool HumanoidState::climbableInFront(Adorn* adorn)
{
	const G3D::CoordinateFrame& torso = humanoid->getTorsoBody()->getCoordinateFrame();
	GeometryService* geometryService = ServiceProvider::find<GeometryService>(humanoid);
	G3D::Vector3 center = torso.translation + torso.lookVector() * 2.0f * 0.5f;
	Extents extents(center - G3D::Vector3(1.0f, 2.7f, 1.0f), center + G3D::Vector3(1.0f, 0.0f, 1.0f));
	array14.fastClear();
	geometryService->getPartsTouchingExtents(extents, NULL, array14);

	Instance* character = humanoid->getParent();
	int count = array14.size();
	for (int i = 0; i < count; ++i)
	{
		PartInstance* part = array14[i];
		if (!donorIsDescendentOf(part, character))
		{
			if (adorn)
				Draw::selectionBox(part->getPart(), adorn, G3D::Color4(G3D::Color3::red()));
			return true;
		}
	}
	if (adorn)
	{
		adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
		adorn->box(G3D::AABox(extents.min(), extents.max()), G3D::Color4(1.0f, 0.2f, 0.2f, 0.5f), G3D::Color4::zero());
	}
	return false;
}

// Not yet written (batch 28, decoded only; declared in humanoid/HumanoidState.h, belong in this native-Body unit):
//   findFloor 00644000 (1045 B): torso Primitive frame 005e82c0 and grid size * 0.5, max distance 1.0 or leg grid y *
//     (floorPart ? 1.5 : 1.1) + 1.0 (right leg, else left leg), Ray::fromOriginAndDirection 00518830 down (-unitY
//     static 0097289x) from pointToWorldSpace 004766a0, helper 00643f10 (ray cast: ContactManager 0060da00 with this
//     HitTestFilter (+4), floorTouchInWorld +0x2c, PartInstance::fromPrimitive 00599f80, shared_from 00618a40) into
//     floorPart; then a 2x2 loop (x, z in {-1, 1}) of offset rays until a floor is found.
//   findClimbable 00644c80 (985 B): getTorsoBody, climbableInFront(adorn), lookVector 005187f0, 17 rays (i = 1..17,
//     height i / 7 - 2.7) through GeometryService::getHitLocationFilterStairs 0062dc10 (hit distance vs 0.7), adorn
//     drawing (Color3 orange / green / purple, DrawAdorn::cylinder 006773f0), climb height window 2.45.

// 006444f0 onFloorStep: byte-exact in native-classes/HumanoidState.cpp since batch 25 (that unit reaches
// humanoid/Humanoid2008.h, world +0x21c, and Humanoid2008.h now declares getPrimitives 005d9db0). Not duplicated here.

}
}
