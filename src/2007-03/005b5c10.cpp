// from server: 98% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/PVInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PVInstance.h"

#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

namespace RBX {

static const Reflection::PropDescriptor<PVInstance, CoordinateFrame> desc_CoordFrame(
	"CoordinateFrame", "Data", NULL, &PVInstance::setPVGridOffsetLegacy, Reflection::PropertyDescriptor::LEGACY
);

static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown(
	"ControllerFlagShown", "Appearance", &PVInstance::getShowControllerFlag, &PVInstance::setShowControllerFlag
);

const char sPVInstance[] = "PVInstance";

const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType(
	"Controller", "Behavior", &PVInstance::getControllerType, &PVInstance::setControllerType
);

// FUNCTION: WEBSERVICE 0x10059d20 FOLDED
// FUNCTION: ROBLOX 0x00407390 FOLDED
unsigned int PVInstance::topHashCode() const
{
	return 0;
}

// FUNCTION: WEBSERVICE 0x10059d20 FOLDED
// FUNCTION: ROBLOX 0x00407390 FOLDED
unsigned int PVInstance::childHashCode() const
{
	return 0;
}

// FUNCTION: WEBSERVICE 0x1005a7f0
// FUNCTION: ROBLOX 0x00565560
bool PVInstance::isControllable() const
{
	return IsControllable;
}

// FUNCTION: WEBSERVICE 0x100990c0
// FUNCTION: ROBLOX 0x005f7390
void PVInstance::moveToPoint(G3D::Vector3 point)
{
	if (Workspace* workspace = Workspace::findWorkspace(this)) {
		workspace->moveToPoint(this, point);
	}
}

// FUNCTION: WEBSERVICE 0x10099100
// FUNCTION: ROBLOX 0x005f73d0
void PVInstance::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	if (propertyElement->getTag().name.compare("Feature") == 0) {
		const RBX::Name* name = NULL;

		const XmlAttribute* attribute = propertyElement->findAttribute(name_name);

		if (attribute != NULL) {
			attribute->getValue(name);
		}

		if (name->name.compare("Part") == 0) {
			readProperties(propertyElement, binder);
			return;
		}

		if (name->name.compare("Item") == 0) {
			readProperties(propertyElement, binder);
			return;
		}
	}

	Instance::readProperty(propertyElement, binder);
}

// FUNCTION: WEBSERVICE 0x100991c0 FOLDED
// FUNCTION: ROBLOX 0x005f7490 FOLDED
void PVInstance::onChildAdded(Instance* instance)
{
	PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);

	if (pvInstance != NULL) {
		pvInstance->onChildControllerChanged();
		pvInstance->onParentControllerChanged();
	}
}

// FUNCTION: WEBSERVICE 0x100991c0 FOLDED
// FUNCTION: ROBLOX 0x005f7490 FOLDED
void PVInstance::onChildRemoving(Instance* instance)
{
	PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);

	if (pvInstance != NULL) {
		pvInstance->onChildControllerChanged();
		pvInstance->onParentControllerChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10099200
// FUNCTION: ROBLOX 0x005f74d0
void PVInstance::renderCoordinateFrame(Adorn* adorn)
{
	adorn->setObjectToWorldMatrix(getLocation());

	adorn->axes(
		G3D::Color4(G3D::Color3::red(), 1.0f),
		G3D::Color4(G3D::Color3::green(), 1.0f),
		G3D::Color4(G3D::Color3::blue(), 1.0f),
		10.0f
	);
}

// FUNCTION: WEBSERVICE 0x100992c0
// FUNCTION: ROBLOX 0x005f7590
void PVInstance::onChildControllerChanged()
{
	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();

	PVInstance* pvInstance = dynamic_cast<PVInstance*>(getParent());

	if (pvInstance != NULL) {
		pvInstance->onChildControllerChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10099300
// FUNCTION: ROBLOX 0x005f75d0
void PVInstance::onDescendentAdded(Instance* instance)
{
	Instance::onDescendentAdded(instance);

	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();
}

// FUNCTION: WEBSERVICE 0x10099330
// FUNCTION: ROBLOX 0x005f7600
void PVInstance::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();

	Instance::onDescendentRemoving(instance);
}

// FUNCTION: WEBSERVICE 0x10099350
// FUNCTION: ROBLOX 0x005f7620
void PVInstance::onExtentsChanged() const
{
	const PVInstance* pvInstance = dynamic_cast<const PVInstance*>(getParent());

	if (pvInstance != NULL) {
		pvInstance->onExtentsChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10099450
// FUNCTION: ROBLOX 0x005f7700
void PVInstance::onParentControllerChanged()
{
	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();

	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* child = (*getChildren())[i].get();
		PVInstance* pvInstance = dynamic_cast<PVInstance*>(child);

		if (pvInstance != NULL) {
			pvInstance->onParentControllerChanged();
		}
	}
}

// FUNCTION: WEBSERVICE 0x100994d0
// FUNCTION: ROBLOX 0x005f7780
bool PVInstance::computeIsControllable() const
{
	for (unsigned int i = 0; i < numChildren(); ++i) {
		Instance* child = (*getChildren())[i].get();
		IControllable* controllable = dynamic_cast<IControllable*>(child);

		if (controllable != NULL && controllable->isControllable()) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10099780
// FUNCTION: ROBLOX 0x005af010
Controller* PVInstance::getTopPVController() const
{
	Controller* controller = TopPVController.getValue().getPointer();

	if (controller != NULL) {
		return controller;
	}

	return NullController::getStaticNullController();
}

// FUNCTION: ROBLOX 0x005f7810
PVInstance* PVInstance::getTopLevelPVParent()
{
	if (isTopLevelPVInstance()) {
		return this;
	}

	return static_cast<PVInstance*>(getParent())->getTopLevelPVParent();
}

// FUNCTION: WEBSERVICE 0x100997e0
// FUNCTION: ROBLOX 0x005f79c0
void PVInstance::clearLegacyOffset()
{
	legacyOffset.reset();

	for (unsigned int i = 0; i < numChildren(); i++) {
		if (PVInstance* pv = dynamic_cast<PVInstance*>(getChild(i))) {
			pv->clearLegacyOffset();
		}
	}
}

// FUNCTION: WEBSERVICE 0x10099870
// FUNCTION: ROBLOX 0x005f7a50
PVInstance::~PVInstance()
{
}

// FUNCTION: WEBSERVICE 0x10099910
// FUNCTION: ROBLOX 0x005f7af0
bool PVInstance::computeIsTopFlag() const
{
	if (IsControllable && controllerType != Controller::NO_CONTROLLER) {
		if (isTopLevelPVInstance()) {
			return true;
		}

		const PVInstance* parentPV = static_cast<const PVInstance*>(getParent());

		return parentPV->getTopPVController()->getControllerType() == Controller::NO_CONTROLLER;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100999a0
// FUNCTION: ROBLOX 0x005f7b80
void PVInstance::setPVGridOffsetLegacy(const CoordinateFrame& _offset)
{
	if (!legacyOffset) {
		legacyOffset.reset(new CoordinateFrame());
		*legacyOffset = _offset;
	}
}

// FUNCTION: WEBSERVICE 0x10099ea0
// FUNCTION: ROBLOX 0x005f8170
G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
{
	if (!isTopLevelPVInstance()) {
		G3D::ReferenceCountedPointer<Controller> parentController =
			static_cast<const PVInstance*>(getParent())->TopPVController;

		if (parentController.notNull() && parentController->getControllerType() != Controller::NO_CONTROLLER) {
			if (!parentController->isUserController()) {
				return parentController.getPointer();
			}
		}
	}

	ControllerService* service = ServiceProvider::create<ControllerService>(this);
	return service ? service->getController(getControllerType(), this) : G3D::ReferenceCountedPointer<Controller>();
}

// FUNCTION: WEBSERVICE 0x1009a3b0
// FUNCTION: ROBLOX 0x005f8680
PVInstance::PVInstance(const char* name)
	: Reflection::Described<PVInstance, sPVInstance, Instance>(name),
	  IsControllable(this, &PVInstance::computeIsControllable), IsTopFlag(this, &PVInstance::computeIsTopFlag),
	  TopPVController(this, &PVInstance::computeTopPVController), controllerType(Controller::NO_CONTROLLER),
	  showControllerFlag(true)
{
}

// FUNCTION: WEBSERVICE 0x1009a4a0
// FUNCTION: ROBLOX 0x005f8770
void PVInstance::setControllerType(Controller::ControllerType _control)
{
	if (controllerType != _control) {
		controllerType = _control;

		onChildControllerChanged();
		onParentControllerChanged();

		raisePropertyChanged(prop_ControllerType);
	}
}

// FUNCTION: WEBSERVICE 0x1009a4e0
// FUNCTION: ROBLOX 0x005f87b0
void PVInstance::setShowControllerFlag(bool _showControllerFlag)
{
	if (showControllerFlag != _showControllerFlag) {
		showControllerFlag = _showControllerFlag;
		raisePropertyChanged(prop_ControllerFlagShown);
	}
}

} // namespace RBX
