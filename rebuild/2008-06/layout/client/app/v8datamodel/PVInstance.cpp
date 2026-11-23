// =============================================================================
// PVInstance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/PVInstance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8datamodel/UserController.h"

namespace RBX
{
	static Reflection::PropDescriptor<PVInstance, G3D::CoordinateFrame> desc_CoordFrame(
		"CoordinateFrame",
		"Data",
		NULL,
		&PVInstance::setPVGridOffsetLegacy,
		Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown(
		"ControllerFlagShown",
		"Appearance",
		&PVInstance::getShowControllerFlag,
		&PVInstance::setShowControllerFlag,
		Reflection::PropertyDescriptor::STANDARD);

	const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType(
		"Controller",
		"Behavior",
		&PVInstance::getControllerType,
		&PVInstance::setControllerType,
		Reflection::PropertyDescriptor::STANDARD);

#pragma warning (push)
#pragma warning (disable : 4355) // 'this' : used in base member initializer list
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

	bool PVInstance::computeIsTopFlag() const
	{
		if (!IsControllable.getValue() || controllerType == Controller::NO_CONTROLLER)
			return false;

		if (isTopLevelPVInstance())
			return true;

		return static_cast<const PVInstance*>(getParent())->getTopPVController()->getControllerType() == Controller::NO_CONTROLLER;
	}

	void PVInstance::setPVGridOffsetLegacy(const G3D::CoordinateFrame& _offset)
	{
		if (!legacyOffset)
		{
			legacyOffset.reset(new G3D::CoordinateFrame());
			*legacyOffset = _offset;
		}
	}

	G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
	{
		if (!isTopLevelPVInstance())
		{
			G3D::ReferenceCountedPointer<Controller> parentController =
				static_cast<const PVInstance*>(getParent())->TopPVController;

			if (parentController.notNull() && parentController->getControllerType() != Controller::NO_CONTROLLER)
			{
				if (!parentController->isUserController())
					return parentController.getPointer();
			}
		}

		ControllerService* service = ServiceProvider::create<ControllerService>(this);
		return service ? service->getController(getControllerType(), this) : G3D::ReferenceCountedPointer<Controller>();
	}

	void PVInstance::setShowControllerFlag(bool _showControllerFlag)
	{
		if (showControllerFlag != _showControllerFlag)
		{
			showControllerFlag = _showControllerFlag;
			raisePropertyChanged(prop_ControllerFlagShown);
		}
	}
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
			PVInstance* pvChild = dynamic_cast<PVInstance*>(getChild(i));
			if (pvChild)
				pvChild->clearLegacyOffset();
		}
	}

#ifdef NATIVE_CONTACTUNIT_PENDING
	void PVInstance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
	{
		if (propertyElement->getTag() == "Feature")
		{
			const Name* name = NULL;
			propertyElement->findAttributeValue(name_name, name);

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

		Instance::readProperty(propertyElement, binder);
	}
#endif

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
			PVInstance* pvChild = dynamic_cast<PVInstance*>(getChild(i));
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
			const IControllable* controllableChild = dynamic_cast<const IControllable*>(getChild(i));
			if (controllableChild)
			{
				if (controllableChild->isControllable())
					return true;
			}
		}

		return false;
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
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class G3D::ReferenceCountedPointer<RBX::Controller>;
template class RBX::Reflection::EnumDesc<enum RBX::Controller::ControllerType>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::Controller::ControllerType>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::Controller::ControllerType> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::Controller::ControllerType> > >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::Controller::ControllerType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Controller::ControllerType> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::Controller::ControllerType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Controller::ControllerType> >,0> >;
template class std::_Vector_val<enum RBX::Controller::ControllerType,std::allocator<enum RBX::Controller::ControllerType> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::Controller::ControllerType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Controller::ControllerType> >,0> >::_Node *>;
template class std::map<RBX::Name const *,enum RBX::Controller::ControllerType,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::Controller::ControllerType> > >;
template class std::vector<enum RBX::Controller::ControllerType,std::allocator<enum RBX::Controller::ControllerType> >;
