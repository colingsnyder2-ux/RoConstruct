#include "v8datamodel/Accoutrement.h"

#include "humanoid/Humanoid.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

#include <boost/bind.hpp>

namespace RBX {

// PORT: 2008 reflection name storage is const pointer, not array.
const char* const sHat = "Hat";

// PORT: 2008 reflection name storage is const pointer, not array.
const char* const sAccoutrement = "Accoutrement";

static Reflection::PropDescriptor<Accoutrement, CoordinateFrame> prop_AttachmentPoint(
	"AttachmentPoint",
	"Appearance",
	&Accoutrement::getAttachmentPoint,
	&Accoutrement::setAttachmentPoint,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos(
	"AttachmentPos",
	"Appearance",
	&Accoutrement::getAttachmentPos,
	&Accoutrement::setAttachmentPos,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward(
	"AttachmentForward",
	"Appearance",
	&Accoutrement::getAttachmentForward,
	&Accoutrement::setAttachmentForward,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp(
	"AttachmentUp",
	"Appearance",
	&Accoutrement::getAttachmentUp,
	&Accoutrement::setAttachmentUp,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight(
	"AttachmentRight",
	"Appearance",
	&Accoutrement::getAttachmentRight,
	&Accoutrement::setAttachmentRight,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState(
	"BackendAccoutrementState",
	"Appearance",
	&Accoutrement::getBackendAccoutrementState,
	&Accoutrement::setBackendAccoutrementState,
	Reflection::PropertyDescriptor::STREAMING
);

bool Accoutrement::writeUnlocked = false;

Accoutrement::AccoutrementState Accoutrement::computeDesiredState(Instance* testParent)
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(testParent);
	if (!humanoid) {
		return IN_WORKSPACE;
	}

	return humanoid->getTorso() ? EQUIPPED : NOTHING;
}

Accoutrement::AccoutrementState Accoutrement::computeDesiredState()
{
	if (!getHandleConst()) {
		return NOTHING;
	}

	if (!Workspace::contextInWorkspace(this)) {
		return HAS_HANDLE;
	}

	return computeDesiredState(getParent());
}

void Accoutrement::setBackendAccoutrementStateNoReplicate(int value)
{
	if (value != backendAccoutrementState) {
		backendAccoutrementState = static_cast<AccoutrementState>(value);
		raisePropertyChanged(prop_BackendAccoutrementState);
	}
}

inline void Accoutrement::upTo_HasHandle()
{
	connectTouchEvent();
}

inline void Accoutrement::upTo_InWorkspace()
{
}

inline void Accoutrement::downFrom_HasHandle()
{
	handleTouched.disconnect();
}

inline void Accoutrement::downFrom_InWorkspace()
{
}

PartInstance* Accoutrement::getHandle()
{
	return const_cast<PartInstance*>(getHandleConst());
}

// FUNCTION: WEBSERVICE 0x100c9e70 FOLDED
// FUNCTION: ROBLOX 0x0060eb20 FOLDED
const PartInstance* Accoutrement::getHandleConst() const
{
	return dynamic_cast<const PartInstance*>(findFirstChildByName("Handle"));
}

// FUNCTION: WEBSERVICE 0x100db450
// FUNCTION: ROBLOX 0x005ba700
void Accoutrement::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	const Name* name = NULL;
	const XmlAttribute* nameAttribute = propertyElement->findAttribute(name_name);

	if (nameAttribute && nameAttribute->getValue(name) && name->name == "BackendAccoutrementState") {
		return;
	}

	Instance::readProperty(propertyElement, binder);
}

// FUNCTION: WEBSERVICE 0x100db4b0
// FUNCTION: ROBLOX 0x005ba760
void Accoutrement::downFrom_InCharacter()
{
	characterChildAdded.disconnect();
	characterChildRemoved.disconnect();
}

// FUNCTION: WEBSERVICE 0x100db4d0
// FUNCTION: ROBLOX 0x005ba780
const G3D::Vector3 Accoutrement::getAttachmentPos() const
{
	return attachmentPoint.translation;
}

// FUNCTION: WEBSERVICE 0x100db500
// FUNCTION: ROBLOX 0x005ba7b0
const G3D::Vector3 Accoutrement::getAttachmentForward() const
{
	return attachmentPoint.lookVector();
}

// FUNCTION: WEBSERVICE 0x100db550
// FUNCTION: ROBLOX 0x005ba800
const G3D::Vector3 Accoutrement::getAttachmentUp() const
{
	return attachmentPoint.upVector();
}

// FUNCTION: WEBSERVICE 0x100db570
// FUNCTION: ROBLOX 0x005ba820
const G3D::Vector3 Accoutrement::getAttachmentRight() const
{
	return attachmentPoint.rightVector();
}

// FUNCTION: WEBSERVICE 0x100db6e0
// FUNCTION: ROBLOX 0x005ba970
const CoordinateFrame Accoutrement::getLocation() const
{
	const PartInstance* handle = getHandleConst();

	return handle ? handle->getCoordinateFrame() : CoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x100db940
// FUNCTION: ROBLOX 0x005bab30
Accoutrement::~Accoutrement()
{
}

// FUNCTION: WEBSERVICE 0x100dbb40
// FUNCTION: ROBLOX 0x005bad30
void Accoutrement::onCameraNear(float distance)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		ICameraSubject* subject = dynamic_cast<ICameraSubject*>(getChild(i));

		if (subject != NULL) {
			subject->onCameraNear(distance);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100dbbd0
// FUNCTION: ROBLOX 0x005badc0
void Accoutrement::render3dSelect(Adorn* adorn, SelectState selectState)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i));

		if (renderable != NULL) {
			renderable->render3dSelect(adorn, selectState);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100dbc60
// FUNCTION: ROBLOX 0x005bae50
void Accoutrement::rebuildBackendState()
{
	AccoutrementState desiredState = computeDesiredState();
	setDesiredState(desiredState, ServiceProvider::findServiceProvider(this));
}

// FUNCTION: WEBSERVICE 0x100dbcd0
// FUNCTION: ROBLOX 0x005baec0
void Accoutrement::onEvent_AddedBackend(boost::shared_ptr<Instance> child)
{
	if (child.get() != this) {
		rebuildBackendState();
	}
}

// FUNCTION: WEBSERVICE 0x100dbd50
// FUNCTION: ROBLOX 0x005baf40
void Accoutrement::onEvent_RemovedBackend(boost::shared_ptr<Instance> child)
{
	if (child.get() != this) {
		if (child.get() == weld.get()) {
			setDesiredState(NOTHING, ServiceProvider::findServiceProvider(this));
		}

		rebuildBackendState();
	}
}

// FUNCTION: WEBSERVICE 0x100dc110
// FUNCTION: ROBLOX 0x005bb2f0
XmlElement* Accoutrement::write()
{
	if (!writeUnlocked) {
		return new XmlElement(tag_External, InstanceHandle(this));
	}

	return Instance::write();
}

// FUNCTION: ROBLOX 0x005bb390
void Accoutrement::dropAllOthers(ModelInstance* model, Accoutrement* accoutrement)
{
	Workspace* workspace = Workspace::findWorkspace(model);
	if (workspace) {
		while (Accoutrement* other = model->findFirstChildOfType<Accoutrement>()) {
			if (other != accoutrement) {
				other->setParent(workspace);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100dc1b0
// FUNCTION: ROBLOX 0x005bb3d0
void Accoutrement::onEvent_HandleTouched(boost::shared_ptr<Instance> other)
{
	if (backendAccoutrementState == IN_WORKSPACE) {
		Instance* character = other->getParent();

		if (Humanoid* humanoid = Humanoid::modelIsCharacter(character)) {
			if (humanoid->getTorso() && !character->findFirstChildOfType<Accoutrement>()) {
				setParent(character);
			}
		}
	}
}

// FUNCTION: ROBLOX 0x005bb4a0
void Accoutrement::dropAll(ModelInstance* model)
{
	dropAllOthers(model, NULL);
}

// FUNCTION: WEBSERVICE 0x100dc3f0
// FUNCTION: ROBLOX 0x005bb620
void Accoutrement::upTo_Equipped()
{
	handleTouched.disconnect();

	std::vector<boost::weak_ptr<PartInstance> > parts;
	PartInstance::findParts(this, parts);
	DragUtilities::unJoinFromOutsiders(parts);

	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* head = humanoid->getHead();
	PartInstance* handle = getHandle();
	buildWeld(head, handle, humanoid->getTopOfHead(), attachmentPoint, "HeadWeld");
}

// FUNCTION: WEBSERVICE 0x100dc810
// FUNCTION: ROBLOX 0x005bbb20
void Accoutrement::connectTouchEvent()
{
	if (const PartInstance* handle = getHandleConst()) {
		handleTouched = PartInstance::event_Touched.connect(
			const_cast<PartInstance*>(handle), boost::bind(&Accoutrement::onEvent_HandleTouched, this, _1), 10
		);
	}
	else {
		handleTouched.disconnect();
	}
}

// FUNCTION: WEBSERVICE 0x100dc8f0
// FUNCTION: ROBLOX 0x005bbc00
void Accoutrement::upTo_InCharacter()
{
	characterChildAdded =
		Instance::event_childAdded.connect(getParent(), boost::bind(&Accoutrement::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved = Instance::event_childRemoved.connect(
		getParent(), boost::bind(&Accoutrement::onEvent_RemovedBackend, this, _1), 10
	);
}

// FUNCTION: WEBSERVICE 0x100dca60
// FUNCTION: ROBLOX 0x005bbd70
void Accoutrement::downFrom_Equipped()
{
	ModelInstance* character = NULL;

	if (weld) {
		if (PartInstance* part0 = weld->getPart0()) {
			character = dynamic_cast<ModelInstance*>(part0->getParent());
		}

		weld->setParent(NULL);
		weld.reset();
	}

	if (Humanoid::modelIsCharacter(character)) {
		CoordinateFrame cf = character->getLocation();
		G3D::Vector3 pos = cf.translation;
		pos.y += 4;
		pos += cf.lookVector() * 8;

		if (PartInstance* handle = getHandle()) {
			handle->moveToPoint(pos);
			handle->setRotationalVelocity(G3D::Vector3(1, 1, 1));
		}
	}

	onCameraNear(999.0f);

	connectTouchEvent();
}

// FUNCTION: WEBSERVICE 0x100dcd00
// FUNCTION: ROBLOX 0x005bc030
Accoutrement::Accoutrement() : backendAccoutrementState(NOTHING)
{
	setName(sAccoutrement);
}

// FUNCTION: WEBSERVICE 0x100dcfb0
// FUNCTION: ROBLOX 0x005bc2e0
void Accoutrement::setBackendAccoutrementState(int value)
{
	if (value != backendAccoutrementState) {
		backendAccoutrementState = static_cast<AccoutrementState>(value);
		raisePropertyChanged(prop_BackendAccoutrementState);
	}
}

// STUB: WEBSERVICE 0x100dcfe0
// STUB: ROBLOX 0x005bc310
void Accoutrement::setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider)
{
	do {
		if (desiredState > backendAccoutrementState) {
			switch (backendAccoutrementState) {
			case IN_CHARACTER:
				upTo_Equipped();
				break;
			case IN_WORKSPACE:
				upTo_InCharacter();
				break;
			case HAS_HANDLE:
				upTo_InWorkspace();
				break;
			case NOTHING:
				upTo_HasHandle();
				break;
			}

			setBackendAccoutrementStateNoReplicate(backendAccoutrementState + 1);
		}
		else if (desiredState < backendAccoutrementState) {
			switch (backendAccoutrementState) {
			case EQUIPPED:
				downFrom_Equipped();
				break;
			case IN_CHARACTER:
				downFrom_InCharacter();
				break;
			case IN_WORKSPACE:
				downFrom_InWorkspace();
				break;
			case HAS_HANDLE:
				downFrom_HasHandle();
				break;
			}

			setBackendAccoutrementStateNoReplicate(backendAccoutrementState - 1);
		}
	} while (desiredState != backendAccoutrementState);
}

// FUNCTION: WEBSERVICE 0x100dd0c0
// FUNCTION: ROBLOX 0x005bc3f0
void Accoutrement::onAncestorChanged(const AncestorChanged& event)
{
	const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
	const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);

	if (oldProvider) {
		if (Network::Players::backendProcessing(oldProvider, true)) {
			setDesiredState(NOTHING, oldProvider);
		}
		else {
			backendAccoutrementState = NOTHING;
		}
	}

	Instance::onAncestorChanged(event);

	if (newProvider && Network::Players::backendProcessing(newProvider, true)) {
		rebuildBackendState();
	}
}

// FUNCTION: WEBSERVICE 0x100dd140
// FUNCTION: ROBLOX 0x005bc470
void Accoutrement::setAttachmentPoint(const CoordinateFrame& value)
{
	if (value != attachmentPoint) {
		attachmentPoint = value;

		if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
			workspace->raiseDrawChanged();
		}

		raisePropertyChanged(prop_AttachmentPoint);

		if (weld) {
			weld->setC1(attachmentPoint);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100dd1d0
// FUNCTION: ROBLOX 0x005bc500
void Accoutrement::setAttachmentPos(const G3D::Vector3& v)
{
	setAttachmentPoint(CoordinateFrame(getAttachmentPoint().rotation, v));
}

// FUNCTION: WEBSERVICE 0x100dd220
// FUNCTION: ROBLOX 0x005bc550
void Accoutrement::setAttachmentForward(const G3D::Vector3& v)
{
	CoordinateFrame c = getAttachmentPoint();
	G3D::Vector3 oldX = c.rotation.getColumn(0);
	G3D::Vector3 oldY = c.rotation.getColumn(1);
	G3D::Vector3 z = -v.direction();
	G3D::Vector3 x = oldY.cross(z);
	x.unitize();
	G3D::Vector3 y = z.cross(x);
	y.unitize();
	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);
	setAttachmentPoint(c);
}

// STUB: WEBSERVICE 0x100dd3a0
// STUB: ROBLOX 0x005bc6d0
void Accoutrement::setAttachmentUp(const G3D::Vector3& v)
{
	CoordinateFrame c = getAttachmentPoint();
	G3D::Vector3 oldX = c.rotation.getColumn(0);
	const G3D::Vector3& oldZ = c.rotation.getColumn(2);
	G3D::Vector3 y = v.direction();
	G3D::Vector3 z = oldX.cross(y);
	z.unitize();
	G3D::Vector3 x = y.cross(z);
	x.unitize();
	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);
	setAttachmentPoint(c);
}

// STUB: WEBSERVICE 0x100dd510
// STUB: ROBLOX 0x005bc840
void Accoutrement::setAttachmentRight(const G3D::Vector3& v)
{
	CoordinateFrame c = getAttachmentPoint();
	G3D::Vector3 oldY = c.rotation.getColumn(1);
	const G3D::Vector3& oldZ = c.rotation.getColumn(2);
	G3D::Vector3 x = v.direction();
	G3D::Vector3 z = x.cross(oldY);
	z.unitize();
	G3D::Vector3 y = z.cross(x);
	y.unitize();
	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);
	setAttachmentPoint(c);
}

// FUNCTION: WEBSERVICE 0x100dd7e0
// FUNCTION: ROBLOX 0x005bcb20
Hat::Hat()
{
	setName(sHat);
}

} // namespace RBX

// PORT: instantiate 2008 pointer-to-name reflection template arguments.
template class RBX::FactoryProduct<RBX::Accoutrement, RBX::Instance, &RBX::sAccoutrement>;
template class RBX::Reflection::Described<
	RBX::Accoutrement,
	&RBX::sAccoutrement,
	RBX::FactoryProduct<RBX::Accoutrement, RBX::Instance, &RBX::sAccoutrement> >;
template class RBX::DescribedCreatable<RBX::Accoutrement, RBX::Instance, &RBX::sAccoutrement>;

// PORT: instantiate 2008 pointer-to-name reflection template arguments.
template class RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, &RBX::sHat>;
template class RBX::Reflection::
	Described<RBX::Hat, &RBX::sHat, RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, &RBX::sHat> >;
template class RBX::DescribedCreatable<RBX::Hat, RBX::Accoutrement, &RBX::sHat>;
