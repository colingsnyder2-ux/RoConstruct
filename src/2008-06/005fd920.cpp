// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Tool.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Tool.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "tool/DragUtilities.h"
#include "util/Name.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ToolMouseCommand.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"

#include <G3D/debugAssert.h>
#include <boost/bind.hpp>

namespace RBX {

const char sTool[] = "Tool";

static Reflection::PropDescriptor<Tool, CoordinateFrame> prop_Grip(
	"Grip", "Appearance", &Tool::getGrip, &Tool::setGrip, Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripPos(
	"GripPos", "Appearance", &Tool::getGripPos, &Tool::setGripPos, Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripForward(
	"GripForward", "Appearance", &Tool::getGripForward, &Tool::setGripForward, Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripUp(
	"GripUp", "Appearance", &Tool::getGripUp, &Tool::setGripUp, Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Tool, G3D::Vector3> prop_GripRight(
	"GripRight", "Appearance", &Tool::getGripRight, &Tool::setGripRight, Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<Tool, int> prop_BackendToolState(
	"BackendToolState",
	"Appearance",
	&Tool::getBackendToolState,
	&Tool::setBackendToolState,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<Tool, int> prop_FrontendActivationState(
	"ActivationState",
	"Appearance",
	&Tool::getFrontendActivationState,
	&Tool::setFrontendActivationState,
	Reflection::PropertyDescriptor::STREAMING
);

Reflection::BoundProp<bool, 1> Tool::prop_Enabled("Enabled", "State", &Tool::enabled);

static Reflection::SignalDesc<Tool, void(boost::shared_ptr<Instance>)> event_Equipped("Equipped", "mouse");
static Reflection::SignalDesc<Tool, void()> event_Unequipped("Unequipped");
static Reflection::SignalDesc<Tool, void()> event_Activated("Activated");
static Reflection::SignalDesc<Tool, void()> event_Deactivated("Deactivated");

// FUNCTION: WEBSERVICE 0x100c9df0
// FUNCTION: ROBLOX 0x0060eaa0
void Tool::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
	const Name* name = NULL;
	const XmlAttribute* nameAttribute = propertyElement->findAttribute(name_name);

	if (nameAttribute && nameAttribute->getValue(name)) {
		if (name->name == "BackendToolState") {
			return;
		}

		if (name->name == "ActivationState") {
			return;
		}
	}

	Instance::readProperty(propertyElement, binder);
}

// FUNCTION: WEBSERVICE 0x100c9e70 FOLDED
// FUNCTION: ROBLOX 0x0060eb20 FOLDED
const PartInstance* Tool::getHandleConst() const
{
	return dynamic_cast<const PartInstance*>(findFirstChildByName("Handle"));
}

// FUNCTION: WEBSERVICE 0x100c9ef0
// FUNCTION: ROBLOX 0x0060eba0
Tool::ToolState Tool::computeDesiredState(Instance* testParent)
{
	Humanoid* humanoid = Humanoid::modelIsCharacter(testParent);
	if (!humanoid) {
		return IN_WORKSPACE;
	}

	if (!humanoid->getTorso()) {
		return IN_CHARACTER;
	}

	if (!humanoid->findRightArm() || !humanoid->findRightShoulder()) {
		return HAS_TORSO;
	}

	return EQUIPPED;
}

// FUNCTION: WEBSERVICE 0x100c9f50
// FUNCTION: ROBLOX 0x0060ec00
void Tool::downFrom_InCharacter()
{
	characterChildAdded.disconnect();
	characterChildRemoved.disconnect();
}

// FUNCTION: WEBSERVICE 0x100c9f70
// FUNCTION: ROBLOX 0x0060ec20
void Tool::downFrom_HasTorso()
{
	torsoChildAdded.disconnect();
	torsoChildRemoved.disconnect();
}

// FUNCTION: WEBSERVICE 0x100c9f90
// FUNCTION: ROBLOX 0x0060ec40
const G3D::Vector3 Tool::getGripPos() const
{
	return grip.translation;
}

// FUNCTION: WEBSERVICE 0x100c9fc0
// FUNCTION: ROBLOX 0x0060ec70
const G3D::Vector3 Tool::getGripForward() const
{
	return grip.lookVector();
}

// FUNCTION: WEBSERVICE 0x100ca010
// FUNCTION: ROBLOX 0x0060ecc0
const G3D::Vector3 Tool::getGripUp() const
{
	return grip.upVector();
}

// FUNCTION: WEBSERVICE 0x100ca030
// FUNCTION: ROBLOX 0x0060ece0
const G3D::Vector3 Tool::getGripRight() const
{
	return grip.rightVector();
}

// FUNCTION: WEBSERVICE 0x100ca230
// FUNCTION: ROBLOX 0x0060eea0
PartInstance* Tool::getHandle()
{
	return const_cast<PartInstance*>(getHandleConst());
}

// FUNCTION: WEBSERVICE 0x100ca240
// FUNCTION: ROBLOX 0x0060eeb0
const CoordinateFrame Tool::getLocation() const
{
	const PartInstance* handle = getHandleConst();

	return handle ? handle->getCoordinateFrame() : CoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x100ca4c0
// FUNCTION: ROBLOX 0x0060f1e0
void Tool::render3dSelect(Adorn* adorn, SelectState selectState)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i));

		if (renderable != NULL) {
			renderable->render3dSelect(adorn, selectState);
		}
	}
}

Tool::ToolState Tool::computeDesiredState()
{
	if (!getHandleConst()) {
		return NOTHING;
	}

	if (!Workspace::contextInWorkspace(this)) {
		return HAS_HANDLE;
	}

	return computeDesiredState(getParent());
}

// FUNCTION: WEBSERVICE 0x100ca550
// FUNCTION: ROBLOX 0x0060f270
void Tool::rebuildBackendState()
{
	ToolState desiredState = computeDesiredState();
	setDesiredState(desiredState, ServiceProvider::findServiceProvider(this));
}

// FUNCTION: WEBSERVICE 0x100ca5a0
// FUNCTION: ROBLOX 0x0060f2c0
void Tool::onEvent_AddedBackend(boost::shared_ptr<Instance> child)
{
	if (child.get() != this) {
		rebuildBackendState();
	}
}

// FUNCTION: WEBSERVICE 0x100ca620
// FUNCTION: ROBLOX 0x0060f340
void Tool::onEvent_RemovedBackend(boost::shared_ptr<Instance> child)
{
	if (ServiceProvider::findServiceProvider(this) && child.get() != this) {
		if (child.get() == weld.get()) {
			setDesiredState(HAS_TORSO, ServiceProvider::findServiceProvider(this));
		}

		rebuildBackendState();
	}
}

// FUNCTION: ROBLOX 0x0060f6b0
void Tool::dropAll(ModelInstance* model)
{
	Workspace* workspace = Workspace::findWorkspace(model);
	if (workspace) {
		while (Tool* tool = model->findFirstChildOfType<Tool>()) {
			tool->setParent(workspace);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100ca990
// FUNCTION: ROBLOX 0x0060f6f0
void Tool::moveAllToolsToBackpack(Network::Player* player)
{
	if (player && player->getCharacter()) {
		ModelInstance* character = player->getCharacter();

		while (Tool* tool = character->findFirstChildOfType<Tool>()) {
			tool->setParent(player->getPlayerBackpack());
		}
	}
}

bool Tool::characterCanUnequipTool(ModelInstance* character)
{
	if (character && Humanoid::modelIsCharacter(character)) {
		if (Tool* tool = character->findFirstChildOfType<Tool>()) {
			return tool->canUnequip();
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100ca9e0
// FUNCTION: ROBLOX 0x0060f740
void Tool::onEvent_HandleTouched(boost::shared_ptr<Instance> other)
{
	if (backendToolState == IN_WORKSPACE) {
		Instance* character = other->getParent();

		if (computeDesiredState(character) == EQUIPPED &&
			characterCanUnequipTool(dynamic_cast<ModelInstance*>(character))) {
			if (Network::Player* player = Network::Players::getPlayerFromCharacter(character)) {
				if (canBePickedUpByPlayer(player)) {
					moveAllToolsToBackpack(player);
					setParent(character);
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100caaf0
// FUNCTION: ROBLOX 0x0060f850
void Tool::onLocalClicked()
{
	Network::Player* player = Network::Players::findLocalPlayer(this);

	if (player && characterCanUnequipTool(player->getCharacter())) {
		if (getParent() == player->getPlayerBackpack()) {
			moveAllToolsToBackpack(player);
			setParent(player->getCharacter());
		}
		else {
			setParent(player->getPlayerBackpack());
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cab80
// FUNCTION: ROBLOX 0x0060f8e0
void Tool::onLocalOtherClicked()
{
	Network::Player* player = Network::Players::findLocalPlayer(this);

	if (player && characterCanUnequipTool(player->getCharacter()) && getParent() != player->getPlayerBackpack()) {
		setParent(player->getPlayerBackpack());
	}
}

// FUNCTION: WEBSERVICE 0x100cafd0
// FUNCTION: ROBLOX 0x0060fba0
Tool::~Tool()
{
}

// FUNCTION: WEBSERVICE 0x100cb270
// FUNCTION: ROBLOX 0x0060fe40
void Tool::upTo_Equipped()
{
	handleTouched.disconnect();

	std::vector<boost::weak_ptr<PartInstance> > parts;
	PartInstance::findParts(this, parts);
	DragUtilities::unJoinFromOutsiders(parts);

	Humanoid* humanoid = Humanoid::modelIsCharacter(getParent());
	PartInstance* arm = humanoid->getRightArm();
	PartInstance* handle = getHandle();
	if (handle) {
		handle->setCanCollide(false);
	}

	buildWeld(arm, handle, humanoid->getRightArmGrip(), grip, "RightGrip");
}

// FUNCTION: WEBSERVICE 0x100cb7f0
// FUNCTION: ROBLOX 0x006103c0
void Tool::connectTouchEvent()
{
	if (const PartInstance* handle = getHandleConst()) {
		handleTouched = PartInstance::event_Touched.connect(
			const_cast<PartInstance*>(handle), boost::bind(&Tool::onEvent_HandleTouched, this, _1), 10
		);
	}
	else {
		handleTouched.disconnect();
	}
}

// FUNCTION: WEBSERVICE 0x100cb8d0
// FUNCTION: ROBLOX 0x006104a0
void Tool::upTo_InCharacter()
{
	characterChildAdded =
		Instance::event_childAdded.connect(getParent(), boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	characterChildRemoved =
		Instance::event_childRemoved.connect(getParent(), boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

// FUNCTION: WEBSERVICE 0x100cba40
// FUNCTION: ROBLOX 0x00610610
void Tool::upTo_HasTorso()
{
	PartInstance* torso = Humanoid::modelIsCharacter(getParent())->getTorso();

	torsoChildAdded = Instance::event_childAdded.connect(torso, boost::bind(&Tool::onEvent_AddedBackend, this, _1), 10);
	torsoChildRemoved =
		Instance::event_childRemoved.connect(torso, boost::bind(&Tool::onEvent_RemovedBackend, this, _1), 10);
}

// FUNCTION: WEBSERVICE 0x100cbbc0
// FUNCTION: ROBLOX 0x00610790
void Tool::downFrom_Equipped()
{
	ModelInstance* character = NULL;

	if (weld) {
		if (PartInstance* part0 = weld->getPart0()) {
			character = dynamic_cast<ModelInstance*>(part0->getParent());
		}

		weld->setParent(NULL);
		weld.reset();
	}

	if (PartInstance* handle = getHandle()) {
		handle->setCanCollide(true);

		if (Humanoid::modelIsCharacter(character)) {
			CoordinateFrame cf = character->getLocation();
			G3D::Vector3 pos = cf.translation;
			pos.y += 4;
			pos += cf.lookVector() * 8;

			handle->setCanCollide(true);
			handle->moveToPoint(pos);
			handle->setRotationalVelocity(G3D::Vector3(1, 1, 1));
		}
	}

	connectTouchEvent();
}

// FUNCTION: WEBSERVICE 0x100cbd60
// FUNCTION: ROBLOX 0x00610930
void Tool::onEquipping()
{
	if (getParent() && getParent() == Network::Players::findLocalCharacter(this)) {
		workspace = ServiceProvider::find<Workspace>(this);
		toolMouseCommand = new ToolMouseCommand(workspace, this);
		workspace->setMouseCommand(toolMouseCommand);
	}
}

// FUNCTION: WEBSERVICE 0x100cc230
// FUNCTION: ROBLOX 0x00610e00
boost::shared_ptr<Mouse> Tool::getMouse()
{
	boost::shared_ptr<Mouse> mouse;

	if (toolMouseCommand) {
		mouse = toolMouseCommand->getMouse();
	}
	else {
		mouse = Creatable<Instance>::create<Mouse>();
	}

	return mouse;
}

void Tool::onUnequipped()
{
	if (toolMouseCommand) {
		toolMouseCommand = NULL;
		workspace->setDefaultMouseCommand();
		workspace = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x100cc300
// FUNCTION: ROBLOX 0x00610ed0
void Tool::setBackendToolStateNoReplicate(int value)
{
	if (backendToolState < EQUIPPED && value >= EQUIPPED) {
		onEquipping();
		event_Equipped.fire(this, getMouse());
	}

	if (value == ACTIVATED) {
		event_Activated.fire(this);
	}

	if (backendToolState == ACTIVATED) {
		event_Deactivated.fire(this);
	}

	if (backendToolState >= EQUIPPED && value < EQUIPPED) {
		event_Unequipped.fire(this);
		onUnequipped();
	}

	backendToolState = static_cast<ToolState>(value);
}

// FUNCTION: WEBSERVICE 0x100cc480
// FUNCTION: ROBLOX 0x00611050
void Tool::setBackendToolState(int value)
{
	if (value != backendToolState) {
		setBackendToolStateNoReplicate(value);
		raisePropertyChanged(prop_BackendToolState);
	}
}

inline void Tool::upTo_Activated()
{
}

inline void Tool::upTo_InWorkspace()
{
}

inline void Tool::upTo_HasHandle()
{
	connectTouchEvent();
}

inline void Tool::downFrom_Activated()
{
}

inline void Tool::downFrom_InWorkspace()
{
}

inline void Tool::downFrom_HasHandle()
{
	handleTouched.disconnect();
}

// STUB: WEBSERVICE 0x100cc4b0
// STUB: ROBLOX 0x00611080
void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
{
	do {
		if (desiredState > backendToolState) {
			switch (backendToolState) {
			case ACTIVATED:
				debugAssert(false);
				break;
			case EQUIPPED:
				upTo_Activated();
				break;
			case HAS_TORSO:
				upTo_Equipped();
				break;
			case IN_CHARACTER:
				upTo_HasTorso();
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

			setBackendToolState(backendToolState + 1);
		}
		else if (desiredState < backendToolState) {
			switch (backendToolState) {
			case EQUIPPED:
				downFrom_Equipped();
				break;
			case HAS_TORSO:
				downFrom_HasTorso();
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
			case NOTHING:
				debugAssert(false);
				break;
			}

			setBackendToolState(backendToolState - 1);
		}
	} while (desiredState != backendToolState);
}

// FUNCTION: WEBSERVICE 0x100cc5c0
// FUNCTION: ROBLOX 0x00611190
void Tool::onAncestorChanged(const AncestorChanged& event)
{
	int oldState = backendToolState;
	const ServiceProvider* oldProvider = ServiceProvider::findServiceProvider(event.oldParent);
	const ServiceProvider* newProvider = ServiceProvider::findServiceProvider(event.newParent);

	if (oldProvider) {
		if (Network::Players::backendProcessing(oldProvider, true)) {
			setDesiredState(NOTHING, oldProvider);
		}
		else {
			setBackendToolStateNoReplicate(NOTHING);
		}
	}

	Instance::onAncestorChanged(event);

	if (newProvider) {
		if (Network::Players::backendProcessing(newProvider, true)) {
			rebuildBackendState();
		}
		else if (getParent() == Network::Players::findLocalCharacter(this)) {
			if (oldState >= EQUIPPED) {
				setBackendToolStateNoReplicate(HAS_TORSO);
			}

			setBackendToolStateNoReplicate(EQUIPPED);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cc720
// FUNCTION: ROBLOX 0x006112f0
void Tool::setGrip(const CoordinateFrame& value)
{
	if (value != grip) {
		grip = value;

		if (Workspace* workspace = ServiceProvider::find<Workspace>(this)) {
			workspace->raiseDrawChanged();
		}

		raisePropertyChanged(prop_Grip);

		if (weld) {
			weld->setC1(grip);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cc7b0
// FUNCTION: ROBLOX 0x00611380
void Tool::setGripPos(const G3D::Vector3& v)
{
	setGrip(CoordinateFrame(getGrip().rotation, v));
}

// FUNCTION: WEBSERVICE 0x100cc800
// FUNCTION: ROBLOX 0x006113d0
void Tool::setGripForward(const G3D::Vector3& v)
{
	CoordinateFrame c = getGrip();
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
	setGrip(c);
}

// STUB: WEBSERVICE 0x100cc980
// STUB: ROBLOX 0x00611550
void Tool::setGripUp(const G3D::Vector3& v)
{
	CoordinateFrame c = getGrip();
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
	setGrip(c);
}

// STUB: WEBSERVICE 0x100ccaf0
// STUB: ROBLOX 0x006116c0
void Tool::setGripRight(const G3D::Vector3& v)
{
	CoordinateFrame c = getGrip();
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
	setGrip(c);
}

// FUNCTION: WEBSERVICE 0x100ccdc0
// FUNCTION: ROBLOX 0x00611960
Tool::Tool() : backendToolState(NOTHING), frontendActivationState(0), enabled(true), toolMouseCommand(NULL)
{
	setName(sTool);
}

// FUNCTION: WEBSERVICE 0x100ccfa0
// FUNCTION: ROBLOX 0x00611b40
void Tool::setFrontendActivationState(int value)
{
	int oldState = frontendActivationState;

	if (value > frontendActivationState) {
		frontendActivationState = value;
		raisePropertyChanged(prop_FrontendActivationState);

		if (ServiceProvider::findServiceProvider(this) && Network::Players::backendProcessing(this, true) &&
			backendToolState >= EQUIPPED) {
			if (value - 1 > oldState) {
				setBackendToolState((value - 1) % 2 ? ACTIVATED : EQUIPPED);
			}

			setBackendToolState(value % 2 ? ACTIVATED : EQUIPPED);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cd030
// FUNCTION: ROBLOX 0x00611bd0
void Tool::activate()
{
	setFrontendActivationState(frontendActivationState + frontendActivationState % 2 + 1);
}

// FUNCTION: WEBSERVICE 0x100cd050
// FUNCTION: ROBLOX 0x00611bf0
void Tool::deactivate()
{
	setFrontendActivationState(frontendActivationState + (frontendActivationState + 1) % 2 + 1);
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Tool, RBX::BackpackItem, RBX::sTool>;
template class RBX::Reflection::
	Described<RBX::Tool, RBX::sTool, RBX::FactoryProduct<RBX::Tool, RBX::BackpackItem, RBX::sTool> >;
template class RBX::DescribedCreatable<RBX::Tool, RBX::BackpackItem, RBX::sTool>;

template const RBX::Name& RBX::Name::doDeclare<RBX::sToolMouseCommand>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sMouse>();
template void RBX::Name::callDoDeclare<RBX::sToolMouseCommand>();
template void RBX::Name::callDoDeclare<RBX::sMouse>();
