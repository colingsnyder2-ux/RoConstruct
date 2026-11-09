// from server: 98% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/PVInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PVInstance.h"

#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

namespace RBX {

static Reflection::PropDescriptor<PVInstance, bool> prop_ControllerFlagShown(
	"ControllerFlagShown",
	"Appearance",
	&RBX::PVInstance::getShowControllerFlag,
	&RBX::PVInstance::setShowControllerFlag
);

const char sPVInstance[] = "PVInstance";

const Reflection::EnumPropDescriptor<PVInstance, Controller::ControllerType> PVInstance::prop_ControllerType(
	"Controller",
	"Behavior",
	&RBX::PVInstance::getControllerType,
	&RBX::PVInstance::setControllerType
);

unsigned int PVInstance::topHashCode() const
{
	STUB(0x10059d20);
	return 0;
}

unsigned int PVInstance::childHashCode() const
{
	STUB(0x10059d21);
	return 0;
}

// FUNCTION: WEBSERVICE 0x1005a7f0
bool PVInstance::isControllable() const
{
	return IsControllable;
}

// FUNCTION: WEBSERVICE 0x1005a830
bool PVInstance::isTopLevelPVInstance() const
{
	return dynamic_cast<const PVInstance*>(getParent()) == NULL || getTypedRoot<PVInstance>() == getParent();
}

// FUNCTION: WEBSERVICE 0x10099100
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

// FUNCTION: WEBSERVICE 0x100991c0
void PVInstance::onChildAdded(Instance* instance)
{
	PVInstance* pvInstance = dynamic_cast<PVInstance*>(instance);

	if (pvInstance != NULL) {
		pvInstance->onChildControllerChanged();
		pvInstance->onParentControllerChanged();
	}
}

void PVInstance::onChildRemoving(Instance* child)
{
	STUB(0x100991c1);
}

// FUNCTION: WEBSERVICE 0x10099200
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
void PVInstance::onDescendentAdded(Instance* instance)
{
	Instance::onDescendentAdded(instance);

	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();
}

// FUNCTION: WEBSERVICE 0x10099330
void PVInstance::onDescendentRemoving(const shared_ptr<Instance>& instance)
{
	TopPVController.setDirty();
	IsControllable.setDirty();
	IsTopFlag.setDirty();

	Instance::onDescendentRemoving(instance);
}

// FUNCTION: WEBSERVICE 0x10099350
void PVInstance::onExtentsChanged() const
{
	const PVInstance* pvInstance = dynamic_cast<const PVInstance*>(getParent());

	if (pvInstance != NULL) {
		pvInstance->onExtentsChanged();
	}
}

// FUNCTION: WEBSERVICE 0x10099450
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
Controller* PVInstance::getTopPVController() const
{
	Controller* controller = TopPVController.getValue().getPointer();

	if (controller != NULL) {
		return controller;
	}

	return NullController::getStaticNullController();
}

// FUNCTION: WEBSERVICE 0x10099870
PVInstance::~PVInstance()
{
}

// FUNCTION: WEBSERVICE 0x10099910
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

// STUB: WEBSERVICE 0x10099ea0
G3D::ReferenceCountedPointer<Controller> PVInstance::computeTopPVController() const
{
	STUB(0x10099ea0);
	return G3D::ReferenceCountedPointer<Controller>();
}

// FUNCTION: WEBSERVICE 0x1009a3b0
PVInstance::PVInstance(const char* name)
	: Reflection::Described<PVInstance, sPVInstance, Instance>(name),
	  IsControllable(this, &PVInstance::computeIsControllable), IsTopFlag(this, &PVInstance::computeIsTopFlag),
	  TopPVController(this, &PVInstance::computeTopPVController), controllerType(Controller::NO_CONTROLLER),
	  showControllerFlag(true)
{
}

// FUNCTION: WEBSERVICE 0x1009a4a0
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
void PVInstance::setShowControllerFlag(bool _showControllerFlag)
{
	if (showControllerFlag != _showControllerFlag) {
		showControllerFlag = _showControllerFlag;
		raisePropertyChanged(prop_ControllerFlagShown);
	}
}

} // namespace RBX
