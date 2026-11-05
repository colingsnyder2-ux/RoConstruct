// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espeon_aug2007_viewport_family_63748df2bdc62be7.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/JointsService.h", "../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp")
#pragma include_alias(<v8datamodel/JointsService.h>, <../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp>)
#pragma include_alias("v8datamodel/DebrisService.h", "../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp")
#pragma include_alias(<v8datamodel/DebrisService.h>, <../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp>)
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
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
	void RunDragger::SnapInfo::updateSurfaceFromHit()
	{
		G3D::Vector3 hitInSnap = snap->getCoordinateFrame().pointToObjectSpace(hitWorld);
		Extents snapExtents = snap->getExtentsLocal();

		surface = snapExtents.closestFace(hitInSnap);
	}

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
	}

	float RunDragger::SnapInfo::hitOutsideExtents()
	{
		Extents snapExtents = snap->getExtentsLocal();
		G3D::Vector3 hitInSnap = snap->getCoordinateFrame().pointToObjectSpace(hitWorld);
		G3D::Vector3 clipInSnap = hitInSnap.clamp(snapExtents.min(), snapExtents.max());

		return (hitInSnap - clipInSnap).magnitude();
	}

	RunDragger::RunDragger()
		: workspace(NULL),
		  drag(NULL)
	{
	}

	RunDragger::~RunDragger() {}

	bool RunDragger::adjacent(Primitive* p0, Primitive* p1)
	{
		for (Contact* current = p0->getFirstContact(); current != NULL; current = p0->getNextContact(current))
		{
			if (current->otherPrimitive(p0) == p1)
				return current->computeIsAdjacent(0.01f);
		}

		return false;
	}

	bool RunDragger::tooCloseToCamera()
	{
		return (drag->getCoordinateFrame().pointToWorldSpace(dragPointLocal) - mouseRay.origin).magnitude() < 6.0f;
	}

	void RunDragger::rotatePart(PartInstance* part)
	{
		RBXASSERT(part);

		G3D::CoordinateFrame rotated = part->getCoordinateFrame();
		Math::rotateMatrixAboutY90(rotated.rotation, 1);

		part->setCoordinateFrame(rotated);
	}

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

	bool RunDragger::notTried(Primitive* check, const G3D::Array<Primitive*>& tried)
	{
		RBXASSERT(check != drag);
		return check && tried.find(check) == tried.end();
	}

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

	void RunDragger::tiltPart(PartInstance* part, const G3D::CoordinateFrame& camera)
	{
		RBXASSERT(part);

		G3D::CoordinateFrame dragCoord = part->getCoordinateFrame();
		G3D::Vector3 axis = Math::getWorldNormal(Math::getClosestObjectNormalId(camera.rightVector(), dragCoord.rotation), dragCoord);
		G3D::Matrix3 tiltM = G3D::Matrix3::fromAxisAngle(axis, G3D::halfPi());

		dragCoord.rotation = tiltM * dragCoord.rotation;
		part->setCoordinateFrame(dragCoord);
	}

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

	void RunDragger::findNoSnapPosition(const G3D::CoordinateFrame& original)
	{
		dragPart.lock()->setCoordinateFrame(original);
		findSafeY();

		RBXASSERT(!workspace->getWorld()->getContactManager().intersectingOthers(drag, 0.01f));
	}
}
