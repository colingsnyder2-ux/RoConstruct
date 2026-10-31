// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_espeon_aug2007_clump_parent_inline_52c1b5635f2f706a.cpp

// Candidate translation unit (score above; library headers required).
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
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_character_state_f342eee04d017582.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_character_state_f342eee04d017582.cpp>)
#pragma include_alias("humanoid/Humanoid.h", "../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp")
#pragma include_alias(<humanoid/Humanoid.h>, <../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp>)
#pragma include_alias("humanoid/Running.h", "../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp")
#pragma include_alias(<humanoid/Running.h>, <../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp>)
#pragma include_alias("humanoid/Balancing.h", "../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp")
#pragma include_alias(<humanoid/Balancing.h>, <../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp>)
#pragma include_alias("humanoid/FallingDown.h", "../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp")
#pragma include_alias(<humanoid/FallingDown.h>, <../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp>)
#pragma include_alias("humanoid/Flying.h", "../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp")
#pragma include_alias(<humanoid/Flying.h>, <../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp>)
#pragma include_alias("humanoid/Freefall.h", "../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp")
#pragma include_alias(<humanoid/Freefall.h>, <../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp>)
#pragma include_alias("humanoid/GettingUp.h", "../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp")
#pragma include_alias(<humanoid/GettingUp.h>, <../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp>)
#pragma include_alias("humanoid/Jumping.h", "../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp")
#pragma include_alias(<humanoid/Jumping.h>, <../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp>)
#pragma include_alias("humanoid/Seated.h", "../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp")
#pragma include_alias(<humanoid/Seated.h>, <../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp>)
#pragma include_alias("RbxGraphics/Adorn.h", "../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp")
#pragma include_alias(<RbxGraphics/Adorn.h>, <../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp>)
#pragma include_alias("AppDraw/AdornG3D.h", "../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp")
#pragma include_alias(<AppDraw/AdornG3D.h>, <../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp>)
#pragma include_alias("v8kernel/Kernel.h", "../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp")
#pragma include_alias(<v8kernel/Kernel.h>, <../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp>)
#pragma include_alias("v8kernel/Point.h", "../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp")
#pragma include_alias(<v8kernel/Point.h>, <../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp>)

#include "v8world/Clump.h"
#include "v8world/Primitive.h"
#include "v8world/RigidJoint.h"
#include "v8world/Anchor.h"
#include "v8world/Assembly.h"
#include <deque>

namespace RBX
{
	// TODO: check which of these are meant for the header

	/*__forceinline*/ Primitive* SpanLink::isSpanningJoint(RigidJoint* r)
	{
		Primitive* prim0 = r->getPrimitive(0);
		Primitive* prim1 = r->getPrimitive(1);
		const Body* body0 = prim0->getBody();
		const Body* body1 = prim1->getBody();

		if (body1->getParent() == body0)
		{
			RBXASSERT(body0->getParent() != body1);
			RBXASSERT(prim0->getClump() == prim1->getClump());
			return prim0;
		}
		else if (body0->getParent() == body1)
		{
			RBXASSERT(prim0->getClump() == prim1->getClump());
			return prim1;
		}

		return NULL;
	}

	bool SpanLink::isDownstreamSpanningJoint(Primitive* p, RigidJoint* r)
	{
		Primitive* prim = isSpanningJoint(r);
		return prim && prim == p;
	}

	SpanLink SpanLink::bestSpanLink(const SpanLink& s0, const SpanLink& s1)
	{
		Primitive* p0 = s0.parent;
		Primitive* p1 = s1.parent;

		if (p0)
		{
			if (p1)
			{
				int p0cd = p0->getClumpDepth();
				int p1cd = p1->getClumpDepth();
				if (p0cd != p1cd)
				{
					return p0cd < p1cd ? s0 : s1;
				}
				else
				{
					float p0ps = p0->getPlanarSize();
					float p1ps = p1->getPlanarSize();

					return (p0ps > p1ps) ? s0 : s1;
				}
			}
			else
			{
				return s0;
			}
		}
		else
		{
			return s1;
		}
	}

	Clump* Clump::otherClump(Edge* e) const
	{
		return e->getPrimitive(0)->getClump() != this ? e->getPrimitive(0)->getClump() : e->getPrimitive(1)->getClump();
	}

	void Clump::addAnchor(Anchor* a)
	{
		RBXASSERT(!anchor);
		RBXASSERT(a->getPrimitive() == rootPrimitive);

		anchor = a;
	}

	Anchor* Clump::removeAnchor()
	{
		RBXASSERT(anchor);

		Anchor* a = anchor;
		anchor = NULL;
		return a;
	}

	bool Clump::inSpanTree(Primitive* p, Primitive* treeRoot)
	{
		Body* treeBody = treeRoot->getBody();
		Body* body = p->getBody();

		while (body)
		{
			if (body == treeBody)
				return true;
			body = body->getParent();
		}
		return false;
	}

	SpanLink Clump::findBestOutsideLink(Primitive* treeRoot, Primitive* current)
	{
		SpanLink bestChildLink;

		RigidJoint* r = current->getFirstRigid();
		while (r != NULL)
		{
			Primitive* other = r->otherPrimitive(current);
			Primitive* prim = SpanLink::isSpanningJoint(r);

			if (prim)
			{
				if (prim == current)
				{
					SpanLink outsideTree = findBestOutsideLink(treeRoot, other);
					bestChildLink = SpanLink::bestSpanLink(bestChildLink, outsideTree);
				}
			}
			else
			{
				if (other->getClump() == current->getClump())
				{
					if (!inSpanTree(other, treeRoot))
					{
						SpanLink outsideTree(other, r);
						bestChildLink = SpanLink::bestSpanLink(bestChildLink, outsideTree);
					}
				}
			}
			r = current->getNextRigid(r);
		}

		return bestChildLink;
	}

	__forceinline void Clump::setParent(Primitive* p, Primitive* newParent)
	{
		p->setClumpDepth(newParent->getClumpDepth() + 1);

		Joint* j = Primitive::getJoint(p, newParent);
		RigidJoint* r = rbx_static_cast<RigidJoint*>(j);

		p->getBody()->setParent(newParent->getBody());
		p->getBody()->setMeInParent(r->getChildInParent(newParent, p));
	}

	void Clump::setSpanParent(Primitive* onTree, RigidJoint* stop)
	{
		for (RigidJoint* r = onTree->getFirstRigid(); r != NULL; r = onTree->getNextRigid(r))
		{
			if (r != stop)
			{
				Primitive* prim = SpanLink::isSpanningJoint(r);
				if (prim && prim != onTree)
				{
					setSpanParent(prim, stop);
					onTree->getBody()->setParent(NULL);
					setParent(prim, onTree);
				}
			}
		}
	}

	void Clump::renumberSpanTree(Primitive* onTree)
	{
		RigidJoint* r = onTree->getFirstRigid();
		while (r != NULL)
		{
			Primitive* p = SpanLink::isSpanningJoint(r);

			if (p && p == onTree)
			{
				Primitive* other = r->otherPrimitive(onTree);
				other->setClumpDepth(onTree->getClumpDepth() + 1);
				renumberSpanTree(other);
			}
			r = onTree->getNextRigid(r);
		}
	}

	// 100% match if inSpanTree has __declspec(noinline)
	bool Clump::spanningTreeAdjust(RigidJoint* removing)
	{
		Primitive* prim = SpanLink::isSpanningJoint(removing);
		RBXASSERT(prim);

		Primitive* otherPrim = removing->otherPrimitive(prim);
		RBXASSERT(otherPrim->getClumpDepth() == prim->getClumpDepth() + 1);

		SpanLink bestLink = findBestOutsideLink(otherPrim, otherPrim);
		RigidJoint* joint = bestLink.joint;
		Primitive* parent = bestLink.parent;
		if (parent)
		{
			RBXASSERT(joint != removing);

			Primitive* otherPrimLink = joint->otherPrimitive(parent);
			RBXASSERT(inSpanTree(otherPrimLink, prim));
			RBXASSERT(inSpanTree(otherPrimLink, otherPrim));
			RBXASSERT(!inSpanTree(parent, otherPrim));

			setSpanParent(otherPrimLink, removing);
			setParent(otherPrimLink, parent);
			renumberSpanTree(otherPrimLink);

			RBXASSERT(inSpanTree(otherPrim, otherPrimLink));
			
			return true;
		}

		return false;
	}

	Body* Clump::getRootBody() const
	{
		RBXASSERT(primitives.size() > 0);
		return rootPrimitive->getBody();
	}

	void Clump::putInKernel(Kernel* kernel)
	{
		RBXASSERT(!anchor);
		return kernel->insertBody(getRootBody());
	}

	void Clump::removeFromKernel(Kernel* kernel)
	{
		RBXASSERT(primitives.size() > 0);
		return kernel->removeBody(getRootBody());
	}

	void Clump::setSleepStatus(Sim::AssemblyState _set)
	{
		RBXASSERT(primitives.size() > 0);
		if (_set != sleepStatus)
		{
			switch (_set)
			{
			case Sim::AWAKE:
				getRootBody()->resetAccumulators();
				break;
			case Sim::SLEEPING_CHECKING:
				getRootBody()->setVelocity(Velocity::zero());
				break;
			case Sim::SLEEPING_DEEPLY:
				getRootBody()->setVelocity(Velocity::zero());
				break;
			}

			sleepStatus = _set;
		}
	}

	void Clump::addPrimitive(Primitive* p, Primitive* parent, RigidJoint* j)
	{
		MaxRadius.setDirty();

		RBXASSERT(!p->getAnchorObject());
		RBXASSERT(!p->getClump());
		RBXASSERT(p->getClumpDepth() == -1);

		p->setClump(this);
		setParent(p, parent);
		bool success = primitives.insert(p).second;
		RBXASSERT(success);
		canSleep = canSleep && p->getCanSleep();
	}

	void Clump::onPrimitiveCanSleepChanged(Primitive* p)
	{
		RBXASSERT(containsPrimitive(p));

		if (p->getCanSleep() && !canSleep)
		{
			canSleep = computeCanSleep();
			return;
		}

		if (!p->getCanSleep() && canSleep)
		{
			canSleep = false;
		}
	}

	bool Clump::calcShouldSleep()
	{
		RBXASSERT(primitives.size() > 0);

		G3D::CoordinateFrame cofm = rootPrimitive->getBody()->getBranchCofmCoordinateFrame();
		runningAverageState.update(cofm, MaxRadius);

		return runningAverageState.withinTolerance(cofm, MaxRadius, 0.02f);
	}

	bool Clump::okNeighborSleep()
	{
		RBXASSERT(primitives.size() > 0);

		G3D::CoordinateFrame cofm = rootPrimitive->getBody()->getBranchCofmCoordinateFrame();
		return runningAverageState.withinTolerance(cofm, MaxRadius, 0.02f);
	}

	bool Clump::forceNeighborAwake()
	{
		RBXASSERT(primitives.size() > 0);

		G3D::CoordinateFrame cofm = rootPrimitive->getBody()->getBranchCofmCoordinateFrame();
		return !runningAverageState.withinTolerance(cofm, MaxRadius, 0.04f);
	}

	bool Clump::computeCanSleep()
	{
		typedef std::set<Primitive*>::iterator Iterator;

		for (Iterator iter = primitives.begin(); iter != primitives.end(); iter++)
		{
			if (!(*iter)->getCanSleep())
				return false;
		}

		return true;
	}

	void Clump::addInconsistent(RigidJoint* r)
	{
		bool success = inconsistentJoints.insert(r).second;
		RBXASSERT(success);
	}

	bool Clump::containsInconsistent(RigidJoint* r)
	{
		return inconsistentJoints.find(r) != inconsistentJoints.end();
	}

	bool Clump::containsPrimitive(Primitive* p) const
	{
		return primitives.find(p) != primitives.end();
	}

	Clump::~Clump()
	{
		RBXASSERT(!rootPrimitive);
		RBXASSERT(primitives.size() == 0);
		RBXASSERT(inconsistentJoints.size() == 0);
		RBXASSERT(!anchor);
	}

	void Clump::removeInconsistent(RigidJoint* r)
	{
		size_t count = inconsistentJoints.erase(r);
		RBXASSERT(count == 1);
	}

	void Clump::removePrimitive(Primitive* p)
	{
		if (p == rootPrimitive)
			rootPrimitive = NULL;

		MaxRadius.setDirty();
		p->setClump(NULL);
		p->setClumpDepth(-1);
		p->getBody()->setParent(NULL);

		size_t count = primitives.erase(p);
		RBXASSERT(count == 1);

		canSleep = computeCanSleep();
	}

	float Clump::computeMaxRadius() const
	{
		typedef std::set<Primitive*>::const_iterator Iterator;

		if (primitives.size() == 1)
			return (rootPrimitive->getGeometry()->getGridSize() * 0.5f).magnitude();
		else
		{
			float answer = 0.0f;

			RBXASSERT(primitives.size() > 0);

			G3D::Vector3 branchPos = rootPrimitive->getBody()->getBranchCofmPos();

			for (Iterator it = primitives.begin(); it != primitives.end(); it++)
			{
				Primitive* current = *it;

				G3D::Vector3 offsetCenter = Math::vector3Abs(current->getBody()->getPV().position.translation - branchPos);
				G3D::Vector3 offset = offsetCenter + current->getGeometry()->getGridSize() * 0.5f;

				answer = G3D::max(answer, offset.magnitude());
			}

			return answer;
		}
	}

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	Clump::Clump(Primitive* root)
		: sleepStatus(Sim::AWAKE),
		  runningAverageState(),
		  assembly(NULL),
		  rootPrimitive(root),
		  anchor(NULL),
		  canSleep(true),
		  primitives(),
		  inconsistentJoints(),
		  MaxRadius(this, &Clump::computeMaxRadius)
	{
		RBXASSERT(root->getClumpDepth() == -1);
		primitives.insert(root);
		root->setClump(this);
		root->setClumpDepth(0);
	}
#pragma warning (pop)

	void Clump::removeAllPrimitives()
	{
		while (primitives.size() != 0)
		{
			removePrimitive(*primitives.begin());
		}
	}

	// inling problem with the 2nd deque.push_back prevents matching
	void Clump::getRigidJoints(std::set<RigidJoint*>& internalRigids, std::set<RigidJoint*>& externalRigids)
	{
		RBXASSERT(rootPrimitive);

		std::deque<Primitive*> deque;
		deque.push_back(rootPrimitive);

		while (!deque.empty())
		{
			Primitive* p = deque.front();
			deque.pop_front();

			for (RigidJoint* r = p->getFirstRigid(); r != NULL; r = p->getNextRigid(r))
			{
				if (r->getPrimitive(0)->getClump() == this && r->getPrimitive(1)->getClump() == this)
				{
					SCOPED(
					if (internalRigids.insert(r).second)
					{
						deque.push_back(r->otherPrimitive(p));
					}
					);
				}
				else
				{
					externalRigids.insert(r);
				}
			}
		}
	}
}
