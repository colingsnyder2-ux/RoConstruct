// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_88d8fbb9bbc451ad.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#undef _DLL
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
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
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_irenderable_header_89bd00a76e9b5599.cpp>)
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
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/Sky.h"
#include "Network/Players.h"
#include "tool/Dragger.h"
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include <boost/bind.hpp>

namespace RBX
{
	const char* sRootInstance = "RootInstance";

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	RootInstance::RootInstance()
		: Base(),
		  ControllersUsed(this, &RootInstance::computeControllersUsed),
		  insertPoint(G3D::Vector3::zero()),
		  viewPort(G3D::Vector2(800.0f, 600.0f)),
		  world(new World())
	{
	}
#pragma warning (pop)

	RootInstance::~RootInstance()
	{
	}

	void RootInstance::onDescendentAdded(Instance* instance)
	{
		ModelInstance::onDescendentAdded(instance);
		ControllersUsed.setDirty();
	}

	void RootInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		ControllersUsed.setDirty();
		ModelInstance::onDescendentRemoving(instance);
	}

	void RootInstance::setInsertPoint(const G3D::Vector3& topCenter)
	{
		insertPoint = Dragger::toGrid(topCenter);
	}

	G3D::Vector3 RootInstance::computeIdeInsertPoint() const
	{
		insertPoint.y = G3D::max(0.0f, insertPoint.y);
		float tempY = insertPoint.y;

		G3D::Vector3 newInsertPoint = getExtentsWorld().clip(insertPoint);

		insertPoint = newInsertPoint;
		insertPoint.y = tempY;

		insertPoint = Dragger::toGrid(insertPoint);
		return insertPoint;
	}

	G3D::Vector3 RootInstance::computeCharacterInsertPoint(const Extents& extents) const
	{
		ModelInstance* character = Network::Players::findLocalCharacter(this);
		if (character)
		{
			G3D::Vector3 cameraLook = getCamera()->getCameraCoordinateFrame().lookVector();
			cameraLook.unitize();

			G3D::Vector3 halfSize = extents.size() * 0.5f;

			std::vector<boost::weak_ptr<PartInstance>> partArray;
			PartInstance::findParts(character, partArray);

			Extents modelExtents = DragUtilities::computeExtents(partArray);

			G3D::Vector3 insertPoint = modelExtents.center() + (cameraLook * 7.0f) + (halfSize * cameraLook) * G3D::Vector3(1,0,1);
			insertPoint = Dragger::toGrid(insertPoint);

			return insertPoint;
		}
		else
		{
			RBXASSERT(0);
			return computeIdeInsertPoint();
		}
	}

	void RootInstance::moveSafe(MegaDragger& megaDragger, G3D::Vector3 move, MoveType moveType)
	{
		megaDragger.startDragging();
		megaDragger.alignAndCleanParts();

		if (moveType == MOVE_DROP)
			megaDragger.safeMoveYDrop(move);
		else
			megaDragger.safeMoveNoDrop(move);

		megaDragger.finishDragging();
	}

	void RootInstance::moveSafe(std::vector<boost::weak_ptr<PartInstance>>& partArray, G3D::Vector3 move, MoveType moveType)
	{
		MegaDragger megaDragger(NULL, partArray, this);
		moveSafe(megaDragger, move, moveType);
	}

	void RootInstance::moveToPoint(PVInstance* pv, G3D::Vector3 point)
	{
		if (this->contains(pv))
		{
			RBXASSERT(pv->getPrimaryPart());

			std::vector<PVInstance*> pvInstances;
			pvInstances.push_back(pv);

			G3D::Vector3 move = Dragger::toGrid(point - pv->getLocation().translation);

			MegaDragger megaDragger(pv->getPrimaryPart(), pvInstances, this);
			moveSafe(megaDragger, move, MOVE_NO_DROP);
		}
	}

	void RootInstance::moveToCharacterInsertPoint(std::vector<boost::weak_ptr<PartInstance>>& partArray)
	{
		if (!partArray.empty())
		{
			Extents extents = DragUtilities::computeExtents(partArray);

			G3D::Vector3 characterInsertPoint = computeCharacterInsertPoint(extents);
			G3D::Vector3 moveToInsert = Dragger::toGrid(characterInsertPoint - extents.bottomCenter());

			moveSafe(partArray, moveToInsert, MOVE_DROP);
		}
	}

	void RootInstance::moveToIdeInsertPoint(std::vector<boost::weak_ptr<PartInstance>>& partArray)
	{
		if (!partArray.empty())
		{
			Extents extents = DragUtilities::computeExtents(partArray);

			G3D::Vector3 insertPoint = computeIdeInsertPoint();
			G3D::Vector3 moveToInsert = Dragger::toGrid(insertPoint - extents.bottomCenter());

			moveSafe(partArray, moveToInsert, MOVE_DROP);
		}
	}

	void RootInstance::insertRaw(const std::vector<boost::shared_ptr<Instance>>& instances, Instance* requestedParent, std::vector<boost::weak_ptr<PartInstance>>& partArray)
	{
		RBXASSERT(requestedParent && this->contains(requestedParent));

		std::for_each(instances.begin(), instances.end(), boost::bind(&Instance::setParent, _1, requestedParent));

		for (size_t i = 0; i < instances.size(); ++i)
			PartInstance::findParts(instances[i].get(), partArray);

		DragUtilities::join(partArray);
	}

	void RootInstance::insertToTree(const std::vector<boost::shared_ptr<Instance>>& instances, Instance* requestedParent)
	{
		std::vector<boost::weak_ptr<PartInstance>> partArray;
		insertRaw(instances, requestedParent, partArray);

		if (!partArray.empty())
			moveSafe(partArray, G3D::Vector3::zero(), MOVE_NO_DROP);
	}

	void RootInstance::insertCharacterView(const std::vector<boost::shared_ptr<Instance>>& instances, std::vector<boost::weak_ptr<PartInstance>>& partArray)
	{
		RBXASSERT(instances.size() > 0);

		if (instances.size() == 1)
		{
			Instance* instance = instances[0].get();
			if (dynamic_cast<HopperBin*>(instance))
			{
				Network::Player* localPlayer = Network::Players::findLocalPlayer(this);
				if (localPlayer)
				{
					instance->setParent(localPlayer->getPlayerBackpack());
					return;
				}
			}
		}

		insertRaw(instances, this, partArray);
		moveToCharacterInsertPoint(partArray);
	}

	void RootInstance::insertIdeView(const std::vector<boost::shared_ptr<Instance>>& instances, std::vector<boost::weak_ptr<PartInstance>>& partArray, PromptMode promptMode)
	{
		RBXASSERT(instances.size() > 0);

		if (instances.size() == 1)
		{
			Instance* instance = instances[0].get();
			if (dynamic_cast<HopperBin*>(instance))
			{
				instance->setParent(ServiceProvider::create<StarterPackService>(this));
				return;
			}
			else if (dynamic_cast<Tool*>(instance))
			{
				if (promptMode == ALLOW_PROMPTS && MessageBoxA(NULL, "Put this tool into the starter pack (otherwise drop into the 3d view)?", "Inserting Tool", MB_YESNO) == IDYES)
				{
					instance->setParent(ServiceProvider::create<StarterPackService>(this));
					return;
				}
			}
		}

		insertRaw(instances, this, partArray);
		if (!partArray.empty())
		{
			moveToIdeInsertPoint(partArray);
			Extents extents = DragUtilities::computeExtents(partArray);
			getCamera()->lookAt(extents.center());
		}
	}

	void RootInstance::insert3dView(const std::vector<boost::shared_ptr<Instance>>& instances, PromptMode promptMode)
	{
		RBXASSERT(instances.size() > 0);

		std::vector<boost::weak_ptr<PartInstance>> partArray;
		if (Network::Players::findLocalCharacter(this))
			insertCharacterView(instances, partArray);
		else
			insertIdeView(instances, partArray, promptMode);

		if (!partArray.empty())
		{
			Extents extents = DragUtilities::computeExtents(partArray);
			getCamera()->zoomExtents(extents, viewPort, Camera::ZOOM_OUT_ONLY);
		}
	}

	void RootInstance::insertHopperBin(HopperBin* h)	
	{
		Network::Player* localPlayer = Network::Players::findLocalPlayer(this);
		if (localPlayer)
			h->setParent(localPlayer->getPlayerBackpack());
		else
			h->setParent(ServiceProvider::create<StarterPackService>(this));
	}

	void RootInstance::insertSpawnLocation(SpawnLocation* s)
	{
		if (!s->neutral)
		{
			Teams* teams = ServiceProvider::create<Teams>(this);
			if (!teams->teamExists(s->getTeamColor()))
			{
				boost::shared_ptr<Team> team = Creatable<Instance>::create<Team>();
				team->setParent(teams);
				team->setTeamColor(s->getTeamColor());
				team->setName(s->getTeamColor().name() + " Team");
			}
		}
	}

	void RootInstance::insertInstances(const std::vector<boost::shared_ptr<Instance>>& instances, Instance* requestedParent, InsertMode insertMode, PromptMode promptMode)
	{
		RBXASSERT(instances.size() > 0);
		RBXASSERT(!requestedParent || this->contains(requestedParent));
		RBXASSERT(!((insertMode == INSERT_TO_3D_VIEW) && (requestedParent != this)));

		std::vector<boost::shared_ptr<Instance>> remaining;
		for (size_t i = 0; i < instances.size(); ++i)
		{
			Instance* instance = instances[i].get();
			if (Sky* sky = dynamic_cast<Sky*>(instance))
			{
				Lighting* lighting = ServiceProvider::create<Lighting>(this);
				lighting->replaceSky(sky);
			}
			else if (Team* team = dynamic_cast<Team*>(instance))
			{
				instance->setParent(ServiceProvider::create<Teams>(this));
			}
			else if (HopperBin* hopperBin = dynamic_cast<HopperBin*>(instance))
			{
				insertHopperBin(hopperBin);
			}
			else if (SpawnLocation* spawnLocation = dynamic_cast<SpawnLocation*>(instance))	
			{
				insertSpawnLocation(spawnLocation);
				remaining.push_back(instances[i]);
			}
			else
			{
				remaining.push_back(instances[i]);
			}
		}

		if (!remaining.empty())
		{
			if (requestedParent && !this->contains(requestedParent))
				std::for_each(remaining.begin(), remaining.end(), boost::bind(&Instance::setParent, _1, requestedParent));

			switch (insertMode)
			{
			case INSERT_TO_3D_VIEW:
				insert3dView(remaining, promptMode);
				return;
			case INSERT_TO_TREE:
				insertToTree(remaining, requestedParent);
				return;
			case INSERT_RAW:
				{
					std::vector<boost::weak_ptr<PartInstance>> partArray;
					insertRaw(remaining, requestedParent, partArray);
				}
				return;
			}
		}
	}

	ControllerTypeArray RootInstance::computeControllersUsed() const
	{
		ControllerTypeArray array;

		for (size_t i = 0; i < numChildren(); ++i)
		{
			const PVInstance* pvChild = queryTypedChild<PVInstance>(i);
			if (pvChild)
			{
				if (pvChild->isControllable())
					array.setController(pvChild->getControllerType(), true);
			}
		}

		return array;
	}
}
