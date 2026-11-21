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

}
}
