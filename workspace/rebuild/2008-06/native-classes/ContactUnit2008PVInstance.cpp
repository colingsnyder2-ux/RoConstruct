// 2008-06 native RBX::PVInstance unit rows (inactive): the original PVInstance unit 00608950..006099f2 follows the
// Contact unit (00606b00..00608945) and precedes the Feature unit (00609a30..). Declarations come from the shared
// native-headers/v8datamodel/PVInstance.h (read-only here). Layout read from the constructor 006098d0 and the bodies:
//   IsControllable +0x140 (dirty +0x141, object +0x144, getFunc +0x148), IsTopFlag +0x158 (dirty +0x159),
//   TopPVController +0x170 (dirty +0x174, object +0x178, getFunc +0x180), controllerType +0x194,
//   showControllerFlag +0x198, legacyOffset +0x19c; IPrimaryPart / ILocation virtual bases through the vbptr +0x134;
//   Instance parent +0x104, children (copy_on_write_ptr) +0x108.
// Verified by tests/record_native_contact_unit2008.py.
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8datamodel/UserController.h"

namespace RBX
{
	// The unit's three descriptors, in donor order (dynamic initializers not recorded here).
	// 0097b9b8: initializer 007f79c0 passes "CoordinateFrame" 00832b2c, "Data" 00822490, no getter, setter 00609150,
	// functionality 0 (LEGACY) to the PropDescriptor constructor 00609410.
	static Reflection::PropDescriptor<PVInstance, G3D::CoordinateFrame> desc_CoordFrame("CoordinateFrame", "Data", NULL, &PVInstance::setPVGridOffsetLegacy, Reflection::PropertyDescriptor::LEGACY);
	// 0097b9d4: the descriptor setShowControllerFlag 00609a00 raises; its getter 00608950 is emitted for it. Initializer
	// 007f7a00 passes "ControllerFlagShown" 0084296c, "Appearance" 008329ac, getter 00608950, setter 00609a00, 5 (STANDARD).
	static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown("ControllerFlagShown", "Appearance", &PVInstance::getShowControllerFlag, &PVInstance::setShowControllerFlag, Reflection::PropertyDescriptor::STANDARD);

	// 0097b994 (setControllerType 006099e5)
	const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType("Controller", "Behavior", &PVInstance::getControllerType, &PVInstance::setControllerType, Reflection::PropertyDescriptor::STANDARD);

#pragma warning (push)
#pragma warning (disable : 4355) // 'this' : used in base member initializer list
	// 006098d0: vbptr +0x134 (0x830fac) when constructing the most-derived object, Instance(name) 0055b960, the
	// Described<PVInstance> descriptor at +0x1c (classDescriptor 00585090), then the members in declaration order.
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

	// 006090c0: isTopLevelPVInstance 005840a0 out of line, the parent's getTopPVController 0059a9e0.
	bool PVInstance::computeIsTopFlag() const
	{
		if (!IsControllable.getValue() || controllerType == Controller::NO_CONTROLLER)
			return false;

		if (isTopLevelPVInstance())
			return true;

		return getTypedParent<PVInstance>()->getTopPVController()->getControllerType() == Controller::NO_CONTROLLER;
	}

	// 00609150: new CoordinateFrame (0x30, ctor 004782d0) only while no legacy offset is stored; no RBXASSERT.
	void PVInstance::setPVGridOffsetLegacy(const G3D::CoordinateFrame& _offset)
	{
		if (!legacyOffset)
		{
			legacyOffset.reset(new G3D::CoordinateFrame());
			*legacyOffset = _offset;
		}
	}

	// 00609690: NOT exact (511 B against 573 B). The original inlines the top-level test as a dynamic_cast of the parent
	// plus an out-of-line getTypedRoot<PVInstance> 005836d0 (and keeps one more RCP copy); here isTopLevelPVInstance()
	// is called out of line, as in computeIsTopFlag 006090c0. Kept because it emits the exact
	// ComputeProp<RCP<Controller>>::operator RCP 00608e70 (TopPVController read). ControllerService::getController
	// 005cbd10, ServiceProvider::create<ControllerService> 005a3330.
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

	// 00609a00
	void PVInstance::setShowControllerFlag(bool _showControllerFlag)
	{
		if (showControllerFlag != _showControllerFlag)
		{
			showControllerFlag = _showControllerFlag;
			raisePropertyChanged(prop_ControllerFlagShown);
		}
	}
	// 00608960: Workspace::findWorkspace 005a3380, RootInstance::moveToPoint 005909e0.
	void PVInstance::moveToPoint(G3D::Vector3 point)
	{
		Workspace* workspace = Workspace::findWorkspace(this);
		if (workspace)
			workspace->moveToPoint(this, point);
	}

	// 00608fa0: scoped_ptr reset (operator delete 006a067a), then the PVInstance children recursively.
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
	// 006089a0: "Feature" (00830598) element whose name attribute is "Part" (008329ec) or "Item" (00830584).
	// Pending: the native v8tree/Instance.h does not declare Instance::readProperties (00557920).
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

	// 00608b60: dirtyAll (+0x174, +0x141, +0x159) then the PVInstance parent (vtable slot 0x48 / 4).
	void PVInstance::onChildControllerChanged()
	{
		dirtyAll();

		PVInstance* pvParent = queryTypedParent<PVInstance>();
		if (pvParent)
			pvParent->onChildControllerChanged();
	}

	// 00608d10
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

	// inline in every caller (TopPVController first: 00608b64 / 00608bad / 00608d13)
	void PVInstance::dirtyAll()
	{
		TopPVController.setDirty();
		IsControllable.setDirty();
		IsTopFlag.setDirty();
	}

	// 00608ba0
	void PVInstance::onDescendentAdded(Instance* instance)
	{
		Instance::onDescendentAdded(instance);

		dirtyAll();
	}

	// 00608bd0
	void PVInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		dirtyAll();

		Instance::onDescendentRemoving(instance);
	}

	// 00608da0: dynamic_cast<const IControllable*> (RTTI 009482a8) of each child, vtable slot 1.
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

	// 00608a60 (onChildAdded and onChildRemoving share the body: ICF)
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

	// 00608aa0
	void PVInstance::renderCoordinateFrame(Adorn* adorn)
	{
		adorn->setObjectToWorldMatrix(getLocation());
		adorn->axes(G3D::Color3::red(), G3D::Color3::green(), G3D::Color3::blue(), 10.0f);
	}

	// 00608bf0
	void PVInstance::onExtentsChanged() const
	{
		const PVInstance* pvParent = queryTypedParent<PVInstance>();
		if (pvParent)
			pvParent->onExtentsChanged();
	}

	// 006099c0: prop_ControllerType 0097b994.
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
