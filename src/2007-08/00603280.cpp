// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_joint_stage_remove_fe9d4241b43f8446.cpp

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

#include "v8world/JointStage.h"
#include "v8world/Edge.h"
#include "v8world/ClumpStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	// TODO: determine which of these functions need to go into the header
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	JointStage::JointStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new ClumpStage(this, world), world)
	{
	}
#pragma warning (pop)

	JointStage::~JointStage()
	{
	}

	// TODO: move to header
	__forceinline bool JointStage::edgeHasPrimitivesDownstream(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);
		return
			p0 &&
			p1 &&
			p0->inPipeline() &&
			p1->inPipeline() &&
			p0->downstreamOfStage(this) &&
			p1->downstreamOfStage(this);
	}

	ClumpStage* JointStage::getClumpStage()
	{
		IStage* downstream = getDownstream();
		return rbx_static_cast<ClumpStage*>(downstream);
	}

	void JointStage::moveEdgeToDownstream(Edge* e)
	{
		RBXASSERT(edgeHasPrimitivesDownstream(e));
		Primitive::insertEdge(e); getClumpStage()->onEdgeAdded(e);
	}

	void JointStage::removeEdgeFromDownstream(Edge* e)
	{
		RBXASSERT(edgeHasPrimitivesDownstream(e));
		getClumpStage()->onEdgeRemoving(e); Primitive::removeEdge(e);
	}

	bool JointStage::pairInMap(Joint* j, Primitive* p)
	{
		typedef std::multimap<Primitive*, Joint*>::const_iterator Iterator;

		for (Iterator it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); it++)
		{
			if (it->second == j)
				return true;
		}

		return false;
	}

	void JointStage::insertToMap(Joint* j, Primitive* p)
	{
		if (!p)
			return;

		RBXASSERT(!pairInMap(j, p));
		jointMap.insert(std::pair<Primitive*, Joint*>(p, j));
	}

	void JointStage::removeFromMap(Joint* j, Primitive* p)
	{
		typedef std::multimap<Primitive*, Joint*>::iterator Iterator;

		if (!p)
			return;

		RBXASSERT(pairInMap(j, p));

		for (Iterator it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); it++)
		{
			if (it->second == j) 
			{
				jointMap.erase(it);
				RBXASSERT(!pairInMap(j, p));
				return;
			}
		}

		RBXASSERT(0);
	}

	// NOTE: might be in headers
	bool JointStage::jointInList(Joint* j)
	{
		return incompleteJoints.find(j) != incompleteJoints.end();
	}

	void JointStage::removeFromList(Joint* j)
	{
		size_t count = incompleteJoints.erase(j);
		RBXASSERT(count == 1);
	}

	void JointStage::insertToList(Joint* j)
	{
		bool result = incompleteJoints.insert(j).second;
		RBXASSERT(result);
	}

	void JointStage::moveJointToDownstream(Joint* j)
	{
		RBXASSERT(!jointInList(j));
		RBXASSERT(!pairInMap(j, j->getPrimitive(0)));
		RBXASSERT(!pairInMap(j, j->getPrimitive(1)));

		moveEdgeToDownstream(j);
	}

	void JointStage::removeJointFromDownstream(Joint* j)
	{
		RBXASSERT(!jointInList(j));
		RBXASSERT(!pairInMap(j, j->getPrimitive(0)));
		RBXASSERT(!pairInMap(j, j->getPrimitive(1)));

		removeEdgeFromDownstream(j);
	}

	void JointStage::onJointPrimitiveNulling(Joint* j, Primitive* nulling)
	{
		RBXASSERT(nulling);
		RBXASSERT(j->links(nulling));
		RBXASSERT(j->downstreamOfStage(this) == edgeHasPrimitivesDownstream(j));
		RBXASSERT(j->downstreamOfStage(this) != jointInList(j));

		if (j->downstreamOfStage(this))
		{
			RBXASSERT(!pairInMap(j, nulling));
			removeJointFromDownstream(j);
			insertToList(j);
			insertToMap(j, j->otherPrimitive(nulling));
		}
		else
		{
			RBXASSERT(j->inStage(this));
			removeFromMap(j, nulling);
		}

		RBXASSERT(!pairInMap(j, nulling));
	}

	void JointStage::onJointPrimitiveSet(Joint* j, Primitive* p)
	{
		RBXASSERT(p);
		RBXASSERT(j->links(p));
		RBXASSERT(!pairInMap(j, p));
		RBXASSERT(j->inStage(this));
		RBXASSERT(jointInList(j));

		if (edgeHasPrimitivesDownstream(j))
		{
			RBXASSERT(!pairInMap(j, p));
			RBXASSERT(pairInMap(j, j->otherPrimitive(p)));

			removeFromList(j);
			removeFromMap(j, j->otherPrimitive(p));
			moveJointToDownstream(j);
		}
		else
		{
			insertToMap(j, p);
		}
	}

	void JointStage::onEdgeAdded(Edge* e)
	{
		e->putInPipeline(this);

		if (edgeHasPrimitivesDownstream(e))
		{
			moveEdgeToDownstream(e);
		}
		else
		{
			RBXASSERT(e->getEdgeType() == Edge::JOINT);
			Joint* j = rbx_static_cast<Joint*>(e);
			insertToList(j);
			insertToMap(j, j->getPrimitive(0));
			insertToMap(j, j->getPrimitive(1));
		}
	}

	void JointStage::onEdgeRemoving(Edge* e)
	{
		if (e->downstreamOfStage(this))
		{
			RBXASSERT(edgeHasPrimitivesDownstream(e));
			removeEdgeFromDownstream(e);
			e->removeFromPipeline(this);
		}
		else
		{
			RBXASSERT(e->getEdgeType() == Edge::JOINT);
			Joint* j = rbx_static_cast<Joint*>(e);
			removeFromList(j);
			removeFromMap(j, j->getPrimitive(0));
			removeFromMap(j, j->getPrimitive(1));
			e->removeFromPipeline(this);
		}
	}

	void JointStage::onPrimitiveAdded(Primitive* p)
	{
		typedef std::multimap<Primitive*, Joint*>::const_iterator Iterator;

		p->putInPipeline(this);
		getClumpStage()->onPrimitiveAdded(p);

		std::vector<Joint*> jointsToPush;

		for (Iterator it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); it++)
		{
			if (edgeHasPrimitivesDownstream(it->second))
				jointsToPush.push_back(it->second);
		}

		for (size_t i = 0; i < jointsToPush.size(); i++)
		{
			Joint* current = jointsToPush[i];

			removeFromList(current);
			removeFromMap(current, p);
			removeFromMap(current, current->otherPrimitive(p));

			moveJointToDownstream(current);
		}
	}

	void JointStage::onPrimitiveRemoving(Primitive* p)
	{
		std::vector<Joint*> tempJointList;

		Joint* j;
		for (j = p->getFirstJoint(); j != NULL; j = p->getNextJoint(j))
		{
			if (j->getJointType() != Joint::ANCHOR_JOINT && j->getJointType() != Joint::FREE_JOINT)
			{
				RBXASSERT(edgeHasPrimitivesDownstream(j));
				tempJointList.push_back(j);
			}
		}

		for (size_t i = 0; i < tempJointList.size(); ++i) // why loop here???
		{
			removeJointFromDownstream(j);
			insertToList(j);
			insertToMap(j, p);

			Primitive* otherP = j->otherPrimitive(p);
			insertToMap(j, otherP);
		}

		getClumpStage()->onPrimitiveRemoving(p);
		p->removeFromPipeline(this);
	}
}