// Rebuild glue for the RBXGSdecomp 42406f1 sync.
// Upstream Sound.cpp now drives FMOD Ex (SDK in tools/rbxgs/Client/fmod per its README),
// and its device enumeration uses SetupAPI.
#include "v8tree/Instance.h"
#include "tool/RunDragger.h"
#include "v8world/Primitive.h"
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"
#include "util/Extents.h"
#include "RenderLib/Profiler.h"

#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "../../../../../tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib")

namespace RBX
{
	// The adopted 2008 Instance.h declares static walkers next to the member ones.
	const Instance* Instance::getRootAncestor(const Instance* instance)
	{
		return instance ? instance->getRootAncestor() : NULL;
	}

	Instance* Instance::getRootAncestor(Instance* instance)
	{
		return instance ? instance->getRootAncestor() : NULL;
	}

	// Upstream Profiler.cpp reads it; no rbxgs unit defines it. Set once a GL context exists.
	bool Render::SpecData::glLoaded = false;

	// 2008 0x0066dd90 (1027 bytes), ported from the server-checked mining unit
	// roc_espeon_dragplacementnativeray01318b1db17f7c05.cpp (73%) onto the real RunDragger.h.
	bool RunDragger::moveDragPart()
	{
		const G3D::CoordinateFrame& snapFrame = snapInfo.snap->getCoordinateFrame();
		G3D::Vector3 normal = Math::getWorldNormal(snapInfo.surface, snapFrame);
		G3D::Matrix3 dragRotation = drag->getCoordinateFrame().rotation;
		G3D::Matrix3 aligned = Math::alignAxesClosest(dragRotation, snapFrame.rotation);
		G3D::Matrix3 relative = dragRotation.transpose() * aligned;
		G3D::Matrix3 rotation = snapFrame.rotation * relative.transpose();
		Math::orthonormalizeIfNecessary(rotation);
		G3D::CoordinateFrame goal(rotation, drag->getCoordinateFrame().translation);
		drag->setCoordinateFrame(goal);
		dragSurface = Math::getClosestObjectNormalId(-normal, rotation);
		G3D::Ray ray = G3D::Ray::fromOriginAndDirection(goal.pointToWorldSpace(dragPointLocal), mouseRay.direction);
		G3D::Ray rayLocal = goal.toObjectSpace(ray);
		Extents extents = drag->getExtentsLocal();
		G3D::Plane plane = extents.getPlane(dragSurface);
		Math::intersectRayPlane(rayLocal, plane, dragHitLocal);
		G3D::Vector3 clamped = dragHitLocal.clamp(extents.min() * 100.0f, extents.max() * 100.0f);
		goal.translation = (goal.translation - goal.pointToWorldSpace(clamped)) + snapInfo.hitWorld;
		dragPart.lock()->setCoordinateFrame(goal);
		return snapDragPart();
	}
}
