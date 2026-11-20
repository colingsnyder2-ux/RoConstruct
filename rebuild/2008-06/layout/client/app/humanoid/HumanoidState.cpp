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

HitTestFilter::Result HumanoidState::filterResult(const Primitive* testMe) const
{
    const Primitive* torso = humanoid->getTorsoPrimitive();
    HitTestFilter::Result result = HitTestFilter::INCLUDE_PRIM;
    if (testMe->getDragging() || testMe->getCanSleep()
        || (torso && torso->getAssembly() == testMe->getAssembly()))
        result = HitTestFilter::IGNORE_PRIM;
    return result;
}

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

}
}
