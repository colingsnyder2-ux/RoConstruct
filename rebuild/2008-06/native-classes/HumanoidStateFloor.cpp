// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Batch 28: the 2008 Body path (native-headers/v8kernel/Body2008.h, canThrottle +0x30) for setLimbFlag 006431b0.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/PartInstance.h"
#include "humanoid/HumanoidState.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/GeometryService.h"   // getPartsTouchingExtents 0062db60 (00644a30)
#include "AppDraw/Draw.h"                   // Draw::selectionBox(const Part&, Adorn*, const Color4&) 00676e00
#include "AppDraw/DrawAdorn.h"              // DrawAdorn::cylinder 006773f0 (findClimbable 00644c80)
#include "RbxGraphics/Adorn.h"
#include <G3D/AABox.h>
#include <G3D/Ray.h>

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

// 00644000 (1045 bytes, plain `ret`; registry placeholder func_00644000, analog name; caller preStep 006451c0).
// Torso Body 005d9160 test, torso Primitive frame 005e82c0, torso grid size * 0.5 (0x819bac); search depth 1.0, or a
// leg's grid y * (floorPart ? 0x81e37c : 0x83a6e4) + 0x827494 (getLeftLegPrimitive 005d90c0, else getRightLegPrimitive
// 005d90e0). First ray from pointToWorldSpace 004766a0 (0, -half.y, 0) down (-Vector3::unitY() static 0x972898), then a
// 2x2 loop x, z in {-1, 1} of corner rays (pointToWorldSpace inlined) until floorPart is found. The helper 00643f10
// (floorPartFromRay) is in HumanoidState.cpp (Humanoid2008.h world +0x21c), byte-identical there.
// PARKED (batch 29, 1029/1045 bytes, first divergence insn 17 only through the shorter branch targets; first real
// difference insn 27 00644050): the target keeps the torso grid-size pointer (`add eax, 4` then [eax], [eax+4], [eax+8])
// and tests floorPart after it, and does not tail-merge the two leg loads (left `mov eax, [eax+0x9c]; fld [eax+8]`,
// right `mov ecx, [eax+0x9c]; fld [ecx+8]`), where the candidate merges them (16 bytes shorter); the corner loop with
// the reused bottom/ray locals and the shared_ptr assignments match apart from edx/eax/ecx rotation. Rejected:
// separate corner/cornerRay locals in the loop (no ray reuse: Ray copied by value into a new slot), a ternary leg
// pointer (right getter called once, 8 bytes shorter), Primitive::getGridSize() inline for the right leg (unchanged).
// Batch 36 rejected: `0.5f * gridSize` (free operator*) for the torso half size: identical output (1029 B, the
// `add eax, 4` pointer form and the leg tail-merge remain).
void HumanoidState::findFloor()
{
	if (!humanoid->getTorsoBody())
		return;
	const G3D::CoordinateFrame& torsoFrame = humanoid->getTorsoPrimitive()->getCoordinateFrame();
	G3D::Vector3 halfSize = humanoid->getTorsoPrimitive()->getGeometry()->getGridSize() * 0.5f;
	float maxDistance = 1.0f;
	float legFactor = floorPart ? 1.5f : 1.1f;
	if (humanoid->getLeftLegPrimitive())
		maxDistance = humanoid->getLeftLegPrimitive()->getGeometry()->getGridSize().y * legFactor + 1.0f;
	else if (humanoid->getRightLegPrimitive())
		maxDistance = humanoid->getRightLegPrimitive()->getGeometry()->getGridSize().y * legFactor + 1.0f;

	G3D::Vector3 bottom = torsoFrame.pointToWorldSpace(G3D::Vector3(0.0f, -halfSize.y, 0.0f));
	G3D::Ray ray = G3D::Ray::fromOriginAndDirection(bottom, -G3D::Vector3::unitY());
	if (floorPart = floorPartFromRay(ray, maxDistance))
		return;

	for (int x = -1; x <= 1; x += 2)
	{
		for (int z = -1; z <= 1; z += 2)
		{
			bottom = torsoFrame.pointToWorldSpace(G3D::Vector3(x * halfSize.x, -halfSize.y, z * halfSize.z));
			ray = G3D::Ray::fromOriginAndDirection(bottom, -G3D::Vector3::unitY());
			if (floorPart = floorPartFromRay(ray, maxDistance))
				return;
		}
	}
}

// 00644c80 (985 bytes, thiscall `ret 4`, al; registry placeholder func_00644c80, analog name; caller preStep 006451c0
// with NULL). Decoded from the target (no donor body): getTorsoBody 005d9160 (NULL -> false), climbableInFront 00644a30
// (false -> false), Body frame (updatePV 00599360, pv +0x94), lookVector 005187f0 * 2.0f [0081c434],
// ServiceProvider::find<GeometryService> 006449e0, Color3::orange 005149b0; 17 rays i = 1..17 at height i / 7
// [0084ac8c = 1/7] - 2.7f [008378b8] (Ray() 00510a30, origin/direction stored), GeometryService::
// getHitLocationFilterStairs 0062dc10 (humanoid parent +0x104, Ray by value with vptr 008282c4); hit distance < 0.7f
// [008288b8]: first hit records the bottom height (Color3::green 005148e0), the first clear ray after it records the
// span (Color3::red, folded with Vector3::unitX 005148b0). With an adorn each ray is drawn (setObjectToWorldMatrix slot
// 14 with CoordinateFrame(Matrix3::identity() 00513e20 [copy 00513220], translation), Adorn::ray slot 21 with
// Ray::fromOriginAndDirection 00518830, Color4(color, 1), 1.0f). Climbable when bottom < 2.45f [0084ac88] and
// 0 < span < 2.45f; then DrawAdorn::cylinder 006773f0 (CoordinateFrame(translation + (0, 5 [0081ccbc], 0)) 0057d210,
// axis 1, 0.2f [008249f8], 1.0f, Color3::purple 00514940).
// PARKED (batch 29, 983/985 bytes, first divergence insn 9 00644c9e): the only difference is register assignment: the
// target keeps this in edi and adorn in ebp (`mov edx, [ebp]` needs a disp8, the 2 bytes), the candidate the mirror.
// Accepted steps: offset Vector3 before Ray() and origin after it (h - 2.7 spilled before the Ray ctor call), a named
// CoordinateFrame and a named drawRay in the adorn block (frame size 0xe8, EH state 1). Rejected for the register
// mirror: the body nested in `if (torsoBody && climbableInFront(adorn))`, separate early returns for the two tests.
bool HumanoidState::findClimbable(Adorn* adorn)
{
	Body* torsoBody = humanoid->getTorsoBody();
	if (!torsoBody || !climbableInFront(adorn))
		return false;

	const G3D::CoordinateFrame& torsoFrame = torsoBody->getCoordinateFrame();
	G3D::Vector3 look = torsoFrame.lookVector();
	GeometryService* geometryService = ServiceProvider::find<GeometryService>(humanoid);
	float bottom = 0.0f;
	float span = 0.0f;
	bool first = true;
	bool inSpan = false;
	G3D::Color3 color = G3D::Color3::orange();
	G3D::Vector3 direction = look * 2.0f;
	for (int i = 1; i < 18; ++i)
	{
		float height = i / 7.0f;
		G3D::Vector3 offset(0.0f, height - 2.7f, 0.0f);
		G3D::Ray ray;
		G3D::Vector3 origin = torsoFrame.translation + offset;
		ray.origin = origin;
		ray.direction = direction;
		G3D::Vector3 hit = geometryService->getHitLocationFilterStairs(humanoid->getParent(), ray);
		if ((hit - origin).length() < 0.7f)
		{
			if (first)
			{
				first = false;
				bottom = height;
				inSpan = true;
				color = G3D::Color3::green();
			}
		}
		else if (inSpan)
		{
			inSpan = false;
			span = height - bottom;
			color = G3D::Color3::red();
		}
		if (adorn)
		{
			G3D::CoordinateFrame frame(G3D::Matrix3::identity(), torsoFrame.translation);
			adorn->setObjectToWorldMatrix(frame);
			G3D::Ray drawRay = G3D::Ray::fromOriginAndDirection(origin - torsoFrame.translation, hit - origin);
			adorn->ray(drawRay, G3D::Color4(color, 1.0f), 1.0f);
		}
	}

	if (bottom < 2.45f && span > 0.0f && span < 2.45f)
	{
		if (adorn)
			DrawAdorn::cylinder(adorn, G3D::CoordinateFrame(torsoFrame.translation + G3D::Vector3(0.0f, 5.0f, 0.0f)), 1, 0.2f, 1.0f, G3D::Color3::purple());
		return true;
	}
	return false;
}

// 006444f0 onFloorStep: byte-exact in native-classes/HumanoidState.cpp since batch 25 (that unit reaches
// humanoid/Humanoid2008.h, world +0x21c, and Humanoid2008.h now declares getPrimitives 005d9db0). Not duplicated here.

}
}
