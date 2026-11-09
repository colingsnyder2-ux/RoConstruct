// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_abstract_family_90fe43be5f84f5c0.cpp

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
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "v8world/Primitive.h"
#include "tool/DragUtilities.h"
#include "AppDraw/Draw.h"

static bool physicalCharacterHacked = false;

namespace RBX
{
	const char* sModel = "Model";

	static const Name& partName = Name::declare(sModel, 2000);

	static Reflection::PropDescriptor<ModelInstance, G3D::CoordinateFrame> desc_ModelInPrimary("ModelInPrimary", "Data", &ModelInstance::getModelInPrimary, &ModelInstance::setModelInPrimary, Reflection::PropertyDescriptor::STREAMING); // L25
	static Reflection::RefPropDescriptor<ModelInstance, PartInstance> primaryPartProp("PrimaryPart", "Data", &ModelInstance::getPrimaryPartInternal, &ModelInstance::setPrimaryPart, Reflection::PropertyDescriptor::STANDARD); // L26
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_breakJoints(&ModelInstance::breakJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller); // L27
	static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_makeJoints(&ModelInstance::makeJoints, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller); // L28

	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunctionOld(&PVInstance::moveToPoint, "move", "location", Reflection::FunctionDescriptor::AnyCaller); // L30
	static Reflection::BoundFuncDesc<ModelInstance, void(G3D::Vector3), 1> model_moveFunction(&PVInstance::moveToPoint, "MoveTo", "location", Reflection::FunctionDescriptor::AnyCaller); // L31

	bool ModelInstance::showModelCoord = false;

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	ModelInstance::ModelInstance()
		: Base("Model"),
		  modelInPrimary(),
		  primaryPart(NULL),
		  FlagHeight(this, &ModelInstance::computeFlagHeight),
		  LocalGridExtents(this, &ModelInstance::computeLocalGridExtents),
		  WorldGridExtents(this, &ModelInstance::computeWorldGridExtents)
	{
		if (!physicalCharacterHacked)
		{
			const Name& name = Name::declare("PhysicalCharacter", -1);
			AbstractFactoryProduct<Instance>::getCreators()[&name] = &getCreator();
			physicalCharacterHacked = true;
		}
	}
#pragma warning (pop)

	ModelInstance::~ModelInstance()
	{
		RBXASSERT(!primaryPart);
	}

	void ModelInstance::dirtyAll() const
	{
		LocalGridExtents.setDirty();
		WorldGridExtents.setDirty();
		FlagHeight.setDirty();
	}

	bool ModelInstance::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const ModelInstance*>(instance) != NULL;
	}

	void ModelInstance::onExtentsChanged() const
	{
		dirtyAll();
		PVInstance::onExtentsChanged();
	}

	void ModelInstance::onDescendentAdded(Instance* instance)
	{
		PVInstance::onDescendentAdded(instance);
		dirtyAll();

		if (instance == candidatePrimaryPart.get())
		{
			RBXASSERT(primaryPart != candidatePrimaryPart.get());
			candidatePrimaryPart.reset();

			updatePrimaryPart(rbx_static_cast<PartInstance*>(instance));
		}

		shouldRenderSetDirty();
	}

	void ModelInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		if (primaryPart == instance.get())
			primaryPart = NULL;

		if (candidatePrimaryPart == instance)
		{
			RBXASSERT(0);
			candidatePrimaryPart.reset();
		}

		dirtyAll();
		shouldRenderSetDirty();
		PVInstance::onDescendentRemoving(instance);
	}

	const Primitive* ModelInstance::getBiggestPrimitive() const
	{
		const PartInstance* primaryPart = getPrimaryPartConst();
		if (primaryPart)
			return primaryPart->getPrimitive();

		return NULL;
	}

	void ModelInstance::updatePrimaryPart(PartInstance* set) const
	{
		if (primaryPart == set)
		{
			RBXASSERT(!set || primaryPart->isDescendentOf(this));
		}
		else if (set)
		{
			RBXASSERT(!set->getParent() || set->isDescendentOf(this));
			if (primaryPart)
			{
				RBXASSERT(primaryPart->isDescendentOf(this));
				G3D::Matrix3 oldMe = getLocation().rotation;
				modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * oldMe, G3D::Vector3::zero());
				primaryPart = set;
			}
			else
			{
				modelInPrimary = G3D::CoordinateFrame();
				primaryPart = set;
			}
		}
		else
		{
			modelInPrimary = G3D::CoordinateFrame();
			primaryPart = NULL;
		}
	}

	void ModelInstance::setPrimaryPart(PartInstance* set)
	{
		if (!set || set->isDescendentOf(this))
		{
			candidatePrimaryPart.reset();
			updatePrimaryPart(set);
		}
		else
		{
			candidatePrimaryPart = shared_from(set);

			if (primaryPart)
			{
				modelInPrimary = G3D::CoordinateFrame();
				primaryPart = NULL;
			}
		}

		raisePropertyChanged(primaryPartProp);
	}

	static void makeJ(Instance* instance)
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->join();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(makeJ);
		}
	}

	void ModelInstance::makeJoints()
	{
		for_eachChild(makeJ);
	}

	static void breakJ(Instance* instance)
	{
		PartInstance* partInstance = dynamic_cast<PartInstance*>(instance);
		if (partInstance)
		{
			partInstance->destroyJoints();
		}
		else
		{
			ModelInstance* modelInstance = dynamic_cast<ModelInstance*>(instance);
			if (modelInstance)
				modelInstance->for_eachChild(breakJ);
		}
	}

	void ModelInstance::breakJoints()
	{
		for_eachChild(breakJ);
	}

	float ModelInstance::computeFlagHeight() const
	{
		float answer = 6.0f;

		if (primaryPart)
		{
			RBXASSERT(primaryPart->isDescendentOf(this));
			float primaryPartY = primaryPart->getExtentsWorld().max().y;
			answer = (getExtentsWorld().max().y - primaryPartY) + 6.0f;
		}

		return answer;
	}

	PartInstance* ModelInstance::getPrimaryPartInternal() const
	{
		if (primaryPart)
		{
			RBXASSERT(primaryPart->isDescendentOf(this));
			return primaryPart;
		}
		else
		{
			float biggest = -1.0f;
			PartInstance* biggestPart = NULL;
			for (size_t i = 0; i < numChildren(); ++i)
			{
				const Instance* child = getChild(i);
				const PVInstance* pvChild = dynamic_cast<const PVInstance*>(child);
				if (pvChild)
				{
					const Primitive* primitive = pvChild->getBiggestPrimitive();
					if (primitive)
					{
						PartInstance* part = PartInstance::fromPrimitive(const_cast<Primitive*>(primitive));
						RBXASSERT(!part || part->isDescendentOf(this));

						float area = part->getExtentsWorld().areaXZ();
						if (area > biggest)
						{
							biggest = area;
							biggestPart = part;
						}
					}
				}
			}

			updatePrimaryPart(biggestPart);
			return biggestPart;
		}
	}

	Extents ModelInstance::computeLocalGridExtents() const
	{
		std::vector<const Primitive*> primitives;
		DragUtilities::getPrimitivesConst(this, primitives);

		Extents answer = Extents::negativeInfiniteExtents();

		for (size_t i = 0; i < primitives.size(); i++)
		{
			const Primitive* primitive = primitives[i];
			Extents localExtents = primitive->getExtentsLocal();
			Extents childExtentsInMe = localExtents.express(primitive->getCoordinateFrame(), getLocation());
			answer.unionWith(childExtentsInMe);
		}

		return primitives.size() != 0 ? answer : Extents::zero();
	}

	Extents ModelInstance::computeWorldGridExtents() const
	{
		return LocalGridExtents.getValue().express(getLocation(), G3D::CoordinateFrame());
	}

	void ModelInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
	{
		RBXASSERT(legacyOffset);

		if (getChildren())
		{
			int count = (int)getChildren()->size();
			if (count > 0)
			{
				G3D::CoordinateFrame myState = parentState * (*legacyOffset);
				for (int i = 0; i < count; ++i)
				{
					Instance* child = getChild(i);
					PVInstance* pvChild = dynamic_cast<PVInstance*>(child);
					if (pvChild)
						pvChild->legacyTraverseState(myState);
				}
			}
		}
	}

	const G3D::CoordinateFrame ModelInstance::getLocation() const
	{
		if (getPrimaryPartConst())
		{
			G3D::CoordinateFrame cf = primaryPart->getCoordinateFrame();
			return G3D::CoordinateFrame(cf.rotation * modelInPrimary.rotation, cf.translation);
		}

		return G3D::CoordinateFrame();
	}

	bool ModelInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			PVInstance* pvChild = dynamic_cast<PVInstance*>(child);
			if (pvChild)
			{
				if (pvChild->hitTest(worldRay, worldHitPoint))
					return true;
			}
		}

		return false;
	}

	bool ModelInstance::shouldRender3dAdorn() const
	{
		return isTopLevelPVInstance() && showModelCoord;
	}

	void ModelInstance::render3dAdorn(Adorn* adorn)
	{
		if (isTopLevelPVInstance())
		{
			if (showModelCoord)
				renderCoordinateFrame(adorn);
		}
	}

	void ModelInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		Extents localExtents = getExtentsLocal();
		G3D::CoordinateFrame location = getLocation();
		location.translation = location.pointToWorldSpace(localExtents.center());

		Part part(Part::BLOCK_PART, localExtents.size(), G3D::Color3::white(), location);
		Draw::selectionBox(part, adorn, selectState);
	}

	void ModelInstance::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			Instance* child = getChild(i);
			ICameraSubject* cameraSubject = dynamic_cast<ICameraSubject*>(child);
			if (cameraSubject)
				cameraSubject->onCameraNear(distance);
		}
	}

	void ModelInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
	{
		DragUtilities::getPrimitivesConst(this, primitives);

		Humanoid* humanoid = findFirstChildOfType<Humanoid>();
		if (humanoid)
			humanoid->getIgnorePrims(primitives);
	}
}
