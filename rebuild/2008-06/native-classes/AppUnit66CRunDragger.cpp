// 2008-06 native RBX::RunDragger unit 0066c330..0066e650 (inactive), against the donor tool/RunDragger.h (read-only; no
// native header declares RunDragger, and its donor layout is the 2008 one: PartDragTool() 00665fc1 news 0x70 before
// RunDragger() 0066c900, whose stores cover dragPart +0x0 / snapPart +0x8 (weak_ptrs released in reverse by ~RunDragger
// 0066c400), workspace +0x10, drag +0x14, dragPointLocal +0x18, snapInfo +0x24 (snap +0x24, surface +0x28 = 6, hitWorld
// +0x2c, lastDragSnap +0x38 = Vector3::inf()), mouseRay +0x44 (G3D::Ray vtable 008282c4, origin +0x48, direction
// +0x54), dragSurface +0x60 and dragHitLocal +0x64; checked by tests/record_native_app_unit66c.py).
// Built with native-headers/part-embedded and native-headers/engine-world first on the include path (the 2008
// Primitive / PartInstance / World / ContactManager declarations), as AppUnit5E4PrimitiveParts.cpp.
// The donor tool/RunDragger.cpp bodies compile exact as they are; the 2008-only members (findSnap, smartPtrHackPre /
// Post, init, fallOffPart, snap, snapDragPart, moveDragPart) are written from the target bytes. RBXASSERT is compiled
// out (/U_RELEASEASSERT): no row of the unit contains assertion code. Codegen analog; names follow the donor header.
#include "tool/RunDragger.h"
#include "tool/Dragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Filters.h"
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Workspace.h"
#include "v8world/Primitive.h"
#include "v8world/Contact.h"
#include "v8world/ContactManager.h"

namespace RBX
{
	// 0066c330
	void RunDragger::SnapInfo::updateSurfaceFromHit()
	{
		G3D::Vector3 hitInSnap = snap->getCoordinateFrame().pointToObjectSpace(hitWorld);
		Extents snapExtents = snap->getExtentsLocal();

		surface = snapExtents.closestFace(hitInSnap);
	}

	// 0066c640 (2008: plus the two function-local debug copies 0097da0c / 0097da20)
	void RunDragger::SnapInfo::updateHitFromSurface(const G3D::Ray& mouseRay)
	{
		Extents snapExtents = snap->getExtentsLocal();
		const G3D::CoordinateFrame& cframe = snap->getCoordinateFrame();

		G3D::Ray rayInSnap = cframe.toObjectSpace(mouseRay);
		G3D::Plane plane = snapExtents.getPlane(surface);
		G3D::Vector3 hitInSnap;

		if (Math::intersectRayPlane(rayInSnap, plane, hitInSnap))
		{
			hitWorld = cframe.pointToWorldSpace(hitInSnap);
		}
		else
		{
			RBXASSERT(0);
			Math::intersectRayPlane(rayInSnap, plane, hitInSnap);
		}

		static G3D::Ray debugRay = rayInSnap;
		static G3D::Plane debugPlane = plane;
	}

	// 0066c810
	float RunDragger::SnapInfo::hitOutsideExtents()
	{
		Extents snapExtents = snap->getExtentsLocal();
		G3D::Vector3 hitInSnap = snap->getCoordinateFrame().pointToObjectSpace(hitWorld);
		G3D::Vector3 clipInSnap = hitInSnap.clamp(snapExtents.min(), snapExtents.max());

		return (hitInSnap - clipInSnap).magnitude();
	}

	// 0066c900 (SnapInfo() 0066c600 inlined; the out-of-line copy is emitted for findSnap)
	RunDragger::RunDragger()
		: workspace(NULL),
		  drag(NULL)
	{
	}

	// 0066c400
	RunDragger::~RunDragger() {}

	// 0066c4c0
	bool RunDragger::adjacent(Primitive* p0, Primitive* p1)
	{
		for (Contact* current = p0->getFirstContact(); current != NULL; current = p0->getNextContact(current))
		{
			if (current->otherPrimitive(p0) == p1)
				return current->computeIsAdjacent(0.01f);
		}

		return false;
	}

	// 0066c510
	bool RunDragger::tooCloseToCamera()
	{
		return (drag->getCoordinateFrame().pointToWorldSpace(dragPointLocal) - mouseRay.origin).magnitude() < 6.0f;
	}

	// 0066c5a0
	void RunDragger::rotatePart(PartInstance* part)
	{
		RBXASSERT(part);

		G3D::CoordinateFrame rotated = part->getCoordinateFrame();
		Math::rotateMatrixAboutY90(rotated.rotation, 1);

		part->setCoordinateFrame(rotated);
	}

	// 0066c970
	RunDragger::SnapInfo RunDragger::createSnapSurface(Primitive* snap, G3D::Array<NormalId>* ignore)
	{
		RBXASSERT(snap);

		SnapInfo answer;
		answer.snap = snap;

		Extents snapExtents = snap->getExtentsLocal();
		const G3D::CoordinateFrame& cframe = snap->getCoordinateFrame();
		G3D::Ray rayInSnap = cframe.toObjectSpace(mouseRay);

		float bestDistance = 0.0f;
		bool found = false;

		for (int i = 0; i < 6; i++)
		{
			NormalId id = (NormalId)i;

			if (!ignore || ignore->find(id) == ignore->end())
			{
				G3D::Plane plane = snapExtents.getPlane(id);
				if (plane.halfSpaceContainsFinite(rayInSnap.origin))
				{
					G3D::Vector3 hitInSnap;
					if (Math::intersectRayPlane(rayInSnap, plane, hitInSnap))
					{
						G3D::Vector3 hitWorld = cframe.pointToWorldSpace(hitInSnap);
						float distance = (mouseRay.origin - hitWorld).magnitude();
						if (distance > bestDistance)
						{
							bestDistance = distance;
							answer.surface = id;
							found = true;
							answer.hitWorld = hitWorld;
						}
					}
				}
			}
		}
		
		return found ? answer : SnapInfo();
	}

	// 0066cc70 (also inlined into snap)
	bool RunDragger::notTried(Primitive* check, const G3D::Array<Primitive*>& tried)
	{
		RBXASSERT(check != drag);
		return check && tried.find(check) == tried.end();
	}

	// 0066ccc0
	RunDragger::SnapInfo RunDragger::bestProximatePart(const G3D::Array<Primitive*>& triedSnap, bool (Contact::* proximityTest)(float))
	{
		SnapInfo answer;

		for (Contact* current = drag->getFirstContact(); current != NULL; current = drag->getNextContact(current))
		{
			if ((current->*proximityTest)(0.01f))
			{
				Primitive* otherPrimitive = current->otherPrimitive(drag);
				if (notTried(otherPrimitive, triedSnap))
				{
					SnapInfo testInfo = createSnapSurface(otherPrimitive, NULL);
					if (testInfo.snap && testInfo.hitOutsideExtents() < 1e+10)
						answer = testInfo;
				}
			}
		}

		return answer;
	}

	// 0066ce20
	void RunDragger::turnUpright(PartInstance* part)
	{
		RBXASSERT(part);

		if (part->getSurfaces().isStandardPart())
		{
			G3D::CoordinateFrame dragCoord = part->getCoordinateFrame();
			if (Math::getClosestObjectNormalId(G3D::Vector3::unitY(), dragCoord.rotation) != NORM_Y)
			{
				dragCoord.rotation = G3D::Matrix3::identity();
				part->setCoordinateFrame(dragCoord);
			}
		}
	}

	// 0066ced0
	void RunDragger::tiltPart(PartInstance* part, const G3D::CoordinateFrame& camera)
	{
		RBXASSERT(part);

		G3D::CoordinateFrame dragCoord = part->getCoordinateFrame();
		G3D::Vector3 axis = Math::getWorldNormal(Math::getClosestObjectNormalId(camera.rightVector(), dragCoord.rotation), dragCoord);
		G3D::Matrix3 tiltM = G3D::Matrix3::fromAxisAngle(axis, G3D::halfPi());

		dragCoord.rotation = tiltM * dragCoord.rotation;
		part->setCoordinateFrame(dragCoord);
	}

	// 0066d0d0
	RunDragger::SnapInfo RunDragger::rayHitsPart(const G3D::Array<Primitive*>& triedSnap, bool forceAdjacent)
	{
		SnapInfo answer;
		PartByLocalCharacter filter((Instance*)workspace);

		if (PartInstance* mousePart = MouseCommand::getMousePart(mouseRay, workspace->getWorld()->getContactManager(), drag, &filter, answer.hitWorld, 2048.0f))
		{
			answer.snap = mousePart->getPrimitive();
			if (notTried(answer.snap, triedSnap) && (!forceAdjacent || adjacent(answer.snap, drag)))
			{
				answer.updateSurfaceFromHit();
				return answer;
			}
		}

		return SnapInfo();
	}

	// 0066d9f0
	bool RunDragger::rayHitsCloserPart()
	{
		G3D::Array<Primitive*> ignoreNone;
		SnapInfo answer = rayHitsPart(ignoreNone, false);

		if (answer.snap && answer.snap != snapInfo.snap)
		{
			if ((answer.hitWorld - mouseRay.origin).magnitude() < (snapInfo.hitWorld - mouseRay.origin).magnitude())
				return true;
		}

		return false;
	}

	// 0066daf0
	void RunDragger::findSafeY()
	{
		if (workspace->getWorld()->getContactManager().intersectingOthers(drag, 0.01f))
		{
			PartInstance* part = PartInstance::fromPrimitive(drag);
			G3D::Array<Primitive*> temp;
			temp.push_back(part->getPrimitive());

			G3D::Vector3 moved = Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), workspace->getWorld()->getContactManager());
			RBXASSERT(moved.x == 0.0f);
			RBXASSERT(moved.y != 0.0f);

			G3D::CoordinateFrame newC = drag->getCoordinateFrame();
			newC.translation += moved;

			dragPart.lock()->setCoordinateFrame(newC);
		}
	}

	// 0066e330
	void RunDragger::findNoSnapPosition(const G3D::CoordinateFrame& original)
	{
		dragPart.lock()->setCoordinateFrame(original);
		findSafeY();

		RBXASSERT(!workspace->getWorld()->getContactManager().intersectingOthers(drag, 0.01f));
	}

	// no row: inlined into snap 0066e550 (World +0x84 ContactManager, intersectingOthers 0060dcd0)
	inline bool RunDragger::colliding()
	{
		return workspace->getWorld()->getContactManager().intersectingOthers(drag, 0.01f);
	}

	// 0066d260
	RunDragger::SnapInfo RunDragger::findSnap(const G3D::Array<Primitive*>& triedSnap)
	{
		SnapInfo answer;

		answer = rayHitsPart(triedSnap, true);
		if (answer.snap)
			return answer;

		answer = bestProximatePart(triedSnap, &Contact::computeIsAdjacent);
		if (answer.snap)
			return answer;

		answer = bestProximatePart(triedSnap, &Contact::computeIsColliding);
		if (answer.snap)
			return answer;

		answer = rayHitsPart(triedSnap, false);
		if (answer.snap)
			return answer;

		return SnapInfo();
	}

	// 0066d430
	void RunDragger::smartPtrHackPre()
	{
		boost::shared_ptr<PartInstance> part = snapPart.lock();
		if (PartInstance::nonNullInWorkspace(part))
			snapInfo.snap = part->getPrimitive();
		else
			snapInfo.snap = NULL;
	}

	// 0066dc80
	void RunDragger::smartPtrHackPost()
	{
		if (snapInfo.snap)
			snapPart = shared_from(PartInstance::fromPrimitive(snapInfo.snap));
		else
			snapPart.reset();
	}

	// 0066d4f0
	void RunDragger::init(Workspace* workspace, boost::weak_ptr<PartInstance> part, const G3D::Vector3& hitPoint)
	{
		this->workspace = workspace;
		dragPart = part;
		drag = part.lock()->getPrimitive();
		dragPointLocal = drag->getCoordinateFrame().pointToObjectSpace(hitPoint);
		drag->setVelocity(Velocity::zero());
		snapInfo = SnapInfo();
		turnUpright(dragPart.lock().get());
	}

	// 0066e1a0 (G3D::Array<NormalId>::append 0066d3c0 / resize 0066cfd0 instantiated here)
	bool RunDragger::fallOffPart(bool& changed)
	{
		G3D::Array<NormalId> tried;
		while (snapInfo.snap)
		{
			Face snapFace = snapInfo.snap->getFaceInWorld(snapInfo.surface);
			Face dragFace = drag->getFaceInWorld(dragSurface);
			if (Face::hasOverlap(snapFace, dragFace, -0.01f))
				break;
			tried.append(snapInfo.surface);
			snapInfo = createSnapSurface(snapInfo.snap, &tried);
			if (!snapInfo.snap)
				break;
			changed = moveDragPart();
		}
		return snapInfo.snap == NULL;
	}

	// 0066e3d0
	bool RunDragger::snap(const G3D::Ray& ray)
	{
		smartPtrHackPre();
		mouseRay = ray;
		G3D::CoordinateFrame original = drag->getCoordinateFrame();
		G3D::Array<Primitive*> tried;

		if (snapInfo.snap)
			snapInfo.updateHitFromSurface(mouseRay);
		else
			snapInfo = findSnap(tried);

		while (snapInfo.snap)
		{
			if (!notTried(snapInfo.snap, tried))
				break;
			tried.append(snapInfo.snap);
			bool moved = moveDragPart();
			if (fallOffPart(moved) || colliding() || rayHitsCloserPart() || tooCloseToCamera())
			{
				snapInfo = findSnap(tried);
			}
			else
			{
				smartPtrHackPost();
				return moved;
			}
		}

		findNoSnapPosition(original);
		smartPtrHackPost();
		return false;
	}

	// 0066d710
	bool RunDragger::snapDragPart()
	{
		Face snapFace = snapInfo.snap->getFaceInWorld(snapInfo.surface);
		Face dragFace = drag->getFaceInWorld(dragSurface);
		G3D::Vector3 snapCorner = snapFace[0];
		G3D::Vector3 dragCorner = dragFace[0];
		G3D::CoordinateFrame snapCoord(snapInfo.snap->getCoordinateFrame().rotation, snapCorner);
		G3D::Vector3 dragInSnap = snapCoord.pointToObjectSpace(dragCorner);
		G3D::Vector3 snapped = Math::iRoundVector3(dragInSnap);
		G3D::Vector3 offset = snapCoord.pointToWorldSpace(snapped) - dragCorner;
		G3D::CoordinateFrame newCoord = drag->getCoordinateFrame();
		newCoord.translation += offset;
		dragPart.lock()->setCoordinateFrame(newCoord);
		if (snapped != snapInfo.lastDragSnap)
		{
			snapInfo.lastDragSnap = snapped;
			return true;
		}
		return false;
	}

	// 0066dd90 (not exact: same size, x87 scheduling of the snap normal differs; see the recorder)
	bool RunDragger::moveDragPart()
	{
		const G3D::CoordinateFrame& snapCoord = snapInfo.snap->getCoordinateFrame();
		G3D::Vector3 snapNormal = Math::getWorldNormal(snapInfo.surface, snapCoord);
		G3D::Matrix3 dragRotation = drag->getCoordinateFrame().rotation;
		G3D::Matrix3 aligned = Math::alignAxesClosest(dragRotation, snapCoord.rotation);
		G3D::Matrix3 relative = dragRotation.transpose() * aligned;
		G3D::Matrix3 rotation = snapCoord.rotation * relative.transpose();
		Math::orthonormalizeIfNecessary(rotation);
		G3D::CoordinateFrame dragCoord(rotation, drag->getCoordinateFrame().translation);
		drag->setCoordinateFrame(dragCoord);
		dragSurface = Math::getClosestObjectNormalId(-snapNormal, rotation);
		G3D::Ray dragRay = G3D::Ray::fromOriginAndDirection(dragCoord.pointToWorldSpace(dragPointLocal), mouseRay.direction);
		G3D::Ray rayInDrag = dragCoord.toObjectSpace(dragRay);
		Extents dragExtents = drag->getExtentsLocal();
		G3D::Plane plane = dragExtents.getPlane(dragSurface);
		Math::intersectRayPlane(rayInDrag, plane, dragHitLocal);
		G3D::Vector3 clipped = dragHitLocal.clamp(dragExtents.min() * 100.0f, dragExtents.max() * 100.0f);
		dragCoord.translation += snapInfo.hitWorld - dragCoord.pointToWorldSpace(clipped);
		dragPart.lock()->setCoordinateFrame(dragCoord);
		return snapDragPart();
	}
}
