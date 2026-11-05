// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_pv_arg_89ef86f80aae23d4.cpp

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
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	const char* sPVInstance = "PVInstance";

	static Reflection::PropDescriptor<PVInstance, G3D::CoordinateFrame> desc_CoordFrame("CoordinateFrame", "Data", NULL, &PVInstance::setPVGridOffsetLegacy, Reflection::PropertyDescriptor::LEGACY); // L23
	static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown("ControllerFlagShown", "Appearance", &PVInstance::getShowControllerFlag, &PVInstance::setShowControllerFlag, Reflection::PropertyDescriptor::STANDARD); // L32
	const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType("Controller", "Behavior", &PVInstance::getControllerType, &PVInstance::setControllerType, Reflection::PropertyDescriptor::STANDARD); // L34

#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	PVInstance::PVInstance(const char* name)
		: Base(name),
		  IsControllable(this, &PVInstance::computeIsControllable),
		  IsTopFlag(this, &PVInstance::computeIsTopFlag),
		  TopPVController(this, &PVInstance::computeTopPVController),
		  controllerType(Controller::NO_CONTROLLER),
		  showControllerFlag(true),
		  legacyOffset(NULL)
	{
	}
#pragma warning (pop)

	void PVInstance::moveToPoint(G3D::Vector3 point)
	{
		Workspace* workspace = Workspace::findWorkspace(this);
		if (workspace)
			workspace->moveToPoint(this, point);
	}

	void PVInstance::clearLegacyOffset()
	{
		legacyOffset.reset();

		for (size_t i = 0; i < numChildren(); ++i)
		{
			PVInstance* pvChild = queryTypedChild<PVInstance>((int)i);
			if (pvChild)
				pvChild->clearLegacyOffset();
		}
	}

	void PVInstance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		if (propertyElement->getTag() == "Feature")
		{
			const Name* name = NULL;

			bool foundNameAttribute = propertyElement->findAttributeValue(name_name, name);
			RBXASSERT(foundNameAttribute);

			if (*name == "Part")
			{
				readProperties(propertyElement, binder);
				return;
			}
			if (*name == "Item")
			{
				readProperties(propertyElement, binder);
				return;
			}
		}

		return Instance::readProperty(propertyElement, binder);
	}

	PVInstance::~PVInstance()
	{
	}

	void PVInstance::onChildControllerChanged()
	{
		dirtyAll();

		PVInstance* pvParent = queryTypedParent<PVInstance>();
		if (pvParent)
			pvParent->onChildControllerChanged();
	}

	void PVInstance::onParentControllerChanged()
	{
		dirtyAll();

		for (size_t i = 0; i < numChildren(); ++i)
		{
			PVInstance* pvChild = queryTypedChild<PVInstance>((int)i);
			if (pvChild)
				pvChild->onParentControllerChanged();
		}
	}

	void PVInstance::dirtyAll()
	{
		TopPVController.setDirty();
		IsControllable.setDirty();
		IsTopFlag.setDirty();
	}

	void PVInstance::onDescendentAdded(Instance* instance)
	{
		Instance::onDescendentAdded(instance);

		dirtyAll();
	}

	void PVInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		dirtyAll();

		Instance::onDescendentRemoving(instance);
	}

	bool PVInstance::computeIsControllable() const
	{
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const IControllable* controllableChild = queryTypedChild<IControllable>((int)i);
			if (controllableChild)
			{
				if (controllableChild->isControllable())
					return true;
			}
		}

		return false;
	}

	G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
	{
		if (!isTopLevelPVInstance())
		{
			G3D::ReferenceCountedPointer<RBX::Controller> controller = getTypedParent<PVInstance>()->TopPVController;

			if (controller.notNull())
			{
				if (controller->getControllerType() != Controller::NO_CONTROLLER && !controller->isUserController())
					return controller;
			}
		}

		ControllerService* controllerService = ServiceProvider::create<ControllerService>(this);
		return controllerService ? controllerService->getController(controllerType, this) : NULL;
	}

	void PVInstance::onChildAdded(Instance* instance)
	{
		PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);
		if (pvInstance)
		{
			pvInstance->onChildControllerChanged();
			pvInstance->onParentControllerChanged();
		}
	}

	void PVInstance::onChildRemoving(Instance* instance)
	{
		PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);
		if (pvInstance)
		{
			pvInstance->onChildControllerChanged();
			pvInstance->onParentControllerChanged();
		}
	}

	void PVInstance::renderCoordinateFrame(Adorn* adorn)
	{
		adorn->setObjectToWorldMatrix(getLocation());
		adorn->axes(G3D::Color3::red(), G3D::Color3::green(), G3D::Color3::blue(), 10.0f);
	}

	bool PVInstance::computeIsTopFlag() const
	{
		if (!IsControllable.getValue() || controllerType == Controller::NO_CONTROLLER)
			return false;

		if (isTopLevelPVInstance())
			return true;

		return getTypedParent<PVInstance>()->getTopPVController()->getControllerType() == Controller::NO_CONTROLLER;
	}

	void PVInstance::setPVGridOffsetLegacy(const G3D::CoordinateFrame& _offset)
	{
		RBXASSERT(this->isTopLevelPVInstance());

		if (!legacyOffset)
		{
			legacyOffset.reset(new G3D::CoordinateFrame());
			*legacyOffset = _offset;
		}
	}

	void PVInstance::onExtentsChanged() const
	{
		const PVInstance* pvParent = queryTypedParent<PVInstance>();
		if (pvParent)
			pvParent->onExtentsChanged();
	}

	void PVInstance::setControllerType(Controller::ControllerType _control)
	{
		if (controllerType != _control)
		{
			controllerType = _control;
			onChildControllerChanged();
			onParentControllerChanged();
			raisePropertyChanged(prop_ControllerType);
		}
	}

	void PVInstance::setShowControllerFlag(bool _showControllerFlag)
	{
		if (showControllerFlag != _showControllerFlag)
		{
			showControllerFlag = _showControllerFlag;
			raisePropertyChanged(prop_ControllerFlagShown);
		}
	}
}
