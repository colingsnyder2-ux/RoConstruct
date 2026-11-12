// from server: 69% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Humanoid.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Humanoid.h"

#include "appdraw/DrawAdorn.h"
#include "humanoid/FallingDown.h"
#include "humanoid/Running.h"
#include "network/Players.h"
#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "util/Color.h"
#include "util/NormalId.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Workspace.h"
#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"
#include "v8tree/Service.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <algorithm>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <stdexcept>
#include <vector>

namespace RBX {

char sHumanoid[] = "Humanoid";

using namespace Reflection;

static RefPropDescriptor<Humanoid, PartInstance> propTorso(
	"Torso", "Data", &Humanoid::getTorso, &Humanoid::setTorso, PropertyDescriptor::UI
);

static RefPropDescriptor<Humanoid, PartInstance> propLeftLeg(
	"LeftLeg", "Data", &Humanoid::getLeftLeg, &Humanoid::setLeftLeg, PropertyDescriptor::UI
);

static RefPropDescriptor<Humanoid, PartInstance> propRightLeg(
	"RightLeg", "Data", &Humanoid::getRightLeg, &Humanoid::setRightLeg, PropertyDescriptor::UI
);

static RefPropDescriptor<Humanoid, PartInstance> propWalkToPart(
	"WalkToPart", "Control", &Humanoid::getWalkToPart, &Humanoid::setWalkToPart, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, G3D::Vector3> propWalkToPoint(
	"WalkToPoint", "Control", &Humanoid::getWalkToPoint, &Humanoid::setWalkToPoint, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, G3D::Vector3> propWalkDirection(
	"WalkDirection", "Control", &Humanoid::getWalkDirection, &Humanoid::setWalkDirection, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, float> propWalkRotationalVelocity(
	"WalkRotationalVelocity",
	"Control",
	&Humanoid::getWalkRotationalVelocity,
	&Humanoid::setWalkRotationalVelocity,
	PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, bool> propJump(
	"Jump", "Control", &Humanoid::getJump, &Humanoid::setJump, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint(
	"TargetPoint", "Control", &Humanoid::getTargetPoint, &Humanoid::setTargetPoint, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, bool> propSit(
	"Sit", "Control", &Humanoid::getSit, &Humanoid::setSit, PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, float> propHealth("Health", "Game", &Humanoid::getHealth, &Humanoid::setHealth);

static PropDescriptor<Humanoid, float> propMaxHealth(
	"MaxHealth", "Game", &Humanoid::getMaxHealth, &Humanoid::setMaxHealth
);

static BoundFuncDesc<Humanoid, void(float), 1> func_TakeDamage(
	&Humanoid::takeDamage, "TakeDamage", "amount", FunctionDescriptor::AnyCaller
);

static BoundFuncDesc<Humanoid, void(G3D::Vector3, boost::shared_ptr<Instance>), 2> func_MoveTo(
	&Humanoid::moveTo2, "MoveTo", "location", "part", FunctionDescriptor::AnyCaller
);

SignalDesc<Humanoid, void()> Humanoid::event_Died("Died");
SignalDesc<Humanoid, void(float)> Humanoid::event_Running("Running", "speed");
SignalDesc<Humanoid, void(float)> Humanoid::event_Climbing("Climbing", "speed");
SignalDesc<Humanoid, void(bool)> Humanoid::event_Jumping("Jumping", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_FreeFalling("FreeFalling", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_GettingUp("GettingUp", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_FallingDown("FallingDown", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_Seated("Seated", "active");

// FUNCTION: WEBSERVICE 0x100a0830
// FUNCTION: ROBLOX 0x005e8db0
PartInstance* Humanoid::getHeadFromCharacter(const ModelInstance* character)
{
	return character ? dynamic_cast<PartInstance*>(character->findFirstChildByName("Head")) : NULL;
}

// FUNCTION: WEBSERVICE 0x100a08d0
// FUNCTION: ROBLOX 0x005e8e50
ModelInstance* Humanoid::getCharacterFromHumanoid(Humanoid* humanoid)
{
	if (humanoid != NULL) {
		Instance* parent = humanoid->getParent();
		ModelInstance* model = dynamic_cast<ModelInstance*>(parent);
		if (model != NULL) {
			return model;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a0900
// FUNCTION: ROBLOX 0x005e8e80
G3D::CoordinateFrame Humanoid::getTopOfHead() const
{
	return G3D::CoordinateFrame(G3D::Matrix3::identity(), G3D::Vector3(0, 0.5f, 0));
}

// FUNCTION: WEBSERVICE 0x100a0930
// FUNCTION: ROBLOX 0x005e8eb0
void Humanoid::renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint)
{
	DrawAdorn::cylinder(
		adorn, G3D::CoordinateFrame(G3D::Matrix3::identity(), waypoint), 1, 0.2f, 1.0f, G3D::Color3::green()
	);
}

// FUNCTION: WEBSERVICE 0x100a0990
// FUNCTION: ROBLOX 0x005e8f10
ContactManager* Humanoid::getContactManager()
{
	World* world = Workspace::getWorldIfInWorkspace(this);

	if (world != NULL) {
		return &world->getContactManager();
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a0bb0
// FUNCTION: ROBLOX 0x005e90f0
PartInstance* Humanoid::getLocalHeadFromContext(const Instance* context)
{
	ModelInstance* character = Network::Players::findLocalCharacter(context);

	return getHeadFromCharacter(character);
}

// FUNCTION: WEBSERVICE 0x100a0bd0
// FUNCTION: ROBLOX 0x005e9110
bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
{
	if (walkToPart != NULL && Workspace::findWorkspace(this) != NULL &&
		Workspace::contextInWorkspace(walkToPart.get())) {
		worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);

		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100a0c50
// FUNCTION: ROBLOX 0x005e9190
G3D::CoordinateFrame Humanoid::getRightArmGrip() const
{
	G3D::CoordinateFrame grip;
	grip.lookAt(G3D::Vector3(0, -1, 0), G3D::Vector3(0, 0, -1));
	grip.translation = G3D::Vector3(0, -1, 0);

	return grip;
}

// FUNCTION: WEBSERVICE 0x100a0cb0
// FUNCTION: ROBLOX 0x005e91f0
PartInstance* Humanoid::findRightArm() const
{
	return static_cast<PartInstance*>(getParent() ? getParent()->findFirstChildByName("Right Arm") : NULL);
}

// FUNCTION: WEBSERVICE 0x100a0d40
// FUNCTION: ROBLOX 0x005e9280
void Humanoid::computeForce(float dt, bool throttling)
{
	if (currentState.get() != NULL) {
		currentState->onComputeForce(dt);
	}
}

// FUNCTION: WEBSERVICE 0x100a0d60
// FUNCTION: ROBLOX 0x005e92a0
void Humanoid::setState(State* state)
{
	if (state != currentState.get()) {
		currentState.reset(state);
	}
}

// FUNCTION: WEBSERVICE 0x100a0da0
// FUNCTION: ROBLOX 0x005e92e0
void Humanoid::onAncestorChanged(const AncestorChanged& event)
{
	World* newWorld = Workspace::getWorldIfInWorkspace(this);
	if (newWorld != world) {
		currentState.reset();

		if (world) {
			world->getKernel().removeConnector2ndPass(this);
		}

		world = newWorld;
		if (world) {
			setState(new Running(this));
			world->getKernel().insertConnector2ndPass(this);
		}
	}

	Instance::onAncestorChanged(event);
}

// FUNCTION: WEBSERVICE 0x100a1100
// FUNCTION: ROBLOX 0x005e96f0
Humanoid::~Humanoid()
{
}

// FUNCTION: WEBSERVICE 0x100a13b0
// FUNCTION: ROBLOX 0x005e99a0
void Humanoid::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
{
	getIgnorePrims(primitives);
}

// FUNCTION: WEBSERVICE 0x100a1480
// FUNCTION: ROBLOX 0x005e9a70
float Humanoid::getIntendedRotationAboutYAxis()
{
	if (currentState.get() != NULL) {
		return currentState->getIntendedRotationAboutYAxis();
	}

	return 0;
}

// FUNCTION: WEBSERVICE 0x10059c10 FOLDED
// FUNCTION: ROBLOX 0x00564b10 FOLDED
bool Humanoid::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const ModelInstance*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100a1840
// FUNCTION: ROBLOX 0x005e9e30
Humanoid* Humanoid::modelIsCharacter(const Instance* testModel)
{
	return testModel ? testModel->findFirstChildOfType<Humanoid>() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a19e0
// FUNCTION: ROBLOX 0x005e9fb0
Humanoid* Humanoid::getLocalHumanoidFromContext(const Instance* context)
{
	return modelIsCharacter(Network::Players::findLocalCharacter(context));
}

// FUNCTION: WEBSERVICE 0x100a1a00
// FUNCTION: ROBLOX 0x005e9fd0
boost::shared_ptr<AutoJoint> newJoint(bool animated)
{
	if (animated) {
		boost::shared_ptr<Motor> m = Creatable<Instance>::create<Motor>();
		m->setMaxVelocity(0.1f);
		return m;
	}

	boost::shared_ptr<Snap> s = Creatable<Instance>::create<Snap>();
	return s;
}

// FUNCTION: WEBSERVICE 0x100a1b00
// FUNCTION: ROBLOX 0x005ea0d0
void Humanoid::render3dAdorn(Adorn* adorn)
{
	if (walkMode == CLICK_TO_MOVE) {
		if (this == getLocalHumanoidFromContext(this)) {
			if (Workspace::findWorkspace(this)) {
				G3D::Vector3 worldPosition;
				if (hasWalkToPoint(worldPosition)) {
					renderWaypoint(adorn, worldPosition);
				}
			}
		}
	}

	if (Running* running = dynamic_cast<Running*>(currentState.get())) {
		running->render3dAdorn(adorn);
	}
}

// FUNCTION: WEBSERVICE 0x100a2010
// FUNCTION: ROBLOX 0x005ea5e0
PartInstance* Humanoid::getHead() const
{
	if (head == NULL && getParent() != NULL) {
		head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));
	}

	return head.get();
}

// FUNCTION: WEBSERVICE 0x100a2110
// FUNCTION: ROBLOX 0x005ea6e0
PartInstance* Humanoid::getTorso() const
{
	if (torso == NULL && getParent() != NULL) {
		torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));
	}

	return torso.get();
}

// FUNCTION: WEBSERVICE 0x100a2210
// FUNCTION: ROBLOX 0x005ea7e0
PartInstance* Humanoid::getLeftLeg() const
{
	if (leftLeg == NULL && getParent() != NULL) {
		leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
	}

	return leftLeg.get();
}

// FUNCTION: WEBSERVICE 0x100a2310
// FUNCTION: ROBLOX 0x005ea8e0
PartInstance* Humanoid::getRightLeg() const
{
	if (rightLeg == NULL && getParent() != NULL) {
		rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));
	}

	return rightLeg.get();
}

// FUNCTION: WEBSERVICE 0x100a2410
// FUNCTION: ROBLOX 0x005ea9e0
PartInstance* Humanoid::getLeftArm() const
{
	if (leftArm == NULL && getParent() != NULL) {
		leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));
	}

	return leftArm.get();
}

// FUNCTION: WEBSERVICE 0x100a2510
// FUNCTION: ROBLOX 0x005eaae0
PartInstance* Humanoid::getRightArm() const
{
	if (rightArm == NULL && getParent() != NULL) {
		rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));
	}

	return rightArm.get();
}

// FUNCTION: WEBSERVICE 0x100a2610
// FUNCTION: ROBLOX 0x005eabe0
JointInstance* Humanoid::findRightShoulder() const
{
	PartInstance* torso = getTorso();
	return static_cast<JointInstance*>(torso ? torso->findFirstChildByName("Right Shoulder") : NULL);
}

// FUNCTION: WEBSERVICE 0x100a26a0
// FUNCTION: ROBLOX 0x005eac70
Primitive* Humanoid::getTorsoPrimitive() const
{
	PartInstance* part = getTorso();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a26c0
// FUNCTION: ROBLOX 0x005eac90
Primitive* Humanoid::getLeftLegPrimitive()
{
	PartInstance* part = getLeftLeg();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a26e0
// FUNCTION: ROBLOX 0x005eacb0
Primitive* Humanoid::getRightLegPrimitive()
{
	PartInstance* part = getRightLeg();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a2700
// FUNCTION: ROBLOX 0x005eacd0
Body* Humanoid::getTorsoBody()
{
	PartInstance* part = getTorso();

	return part != NULL ? part->getPrimitive()->getBody() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a2720
// FUNCTION: ROBLOX 0x005eacf0
Body* Humanoid::getRootBody()
{
	Body* body = getTorsoBody();

	return body != NULL ? body->getRoot() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a2750
// FUNCTION: ROBLOX 0x005ead20
float Humanoid::getTorsoHeading() const
{
	Primitive* torso = getTorsoPrimitive();

	if (torso != NULL) {
		return Math::getHeading(torso->getCoordinateFrame().lookVector());
	}

	return 0.0f;
}

// FUNCTION: WEBSERVICE 0x100a27c0
// FUNCTION: ROBLOX 0x005ead90
const CoordinateFrame Humanoid::getLocation() const
{
	return getHead() != NULL ? getHead()->getCoordinateFrame() : CoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x100a2840
// FUNCTION: ROBLOX 0x005eae10
void Humanoid::buildJoints()
{
	ModelInstance* character = getCharacterFromHumanoid(this);

	if (character) {
		PartInstance* head = getHead();
		PartInstance* torso = getTorso();
		PartInstance* rightArm = getRightArm();
		PartInstance* leftArm = getLeftArm();
		PartInstance* rightLeg = getRightLeg();
		PartInstance* leftLeg = getLeftLeg();

		if (torso) {
			head->getPrimitive()->getBody()->setCanThrottle(false);
			torso->getPrimitive()->getBody()->setCanThrottle(false);
			rightArm->getPrimitive()->getBody()->setCanThrottle(false);
			leftArm->getPrimitive()->getBody()->setCanThrottle(false);
			rightLeg->getPrimitive()->getBody()->setCanThrottle(false);
			leftLeg->getPrimitive()->getBody()->setCanThrottle(false);

			boost::shared_ptr<AutoJoint> rightShoulder = newJoint(true);
			boost::shared_ptr<AutoJoint> leftShoulder = newJoint(true);
			boost::shared_ptr<AutoJoint> rightHip = newJoint(true);
			boost::shared_ptr<AutoJoint> leftHip = newJoint(true);
			boost::shared_ptr<AutoJoint> neck = newJoint(false);

			rightShoulder->setName("Right Shoulder");
			leftShoulder->setName("Left Shoulder");
			rightHip->setName("Right Hip");
			leftHip->setName("Left Hip");
			neck->setName("Neck");

			rightShoulder->setPart0(torso);
			leftShoulder->setPart0(torso);
			rightHip->setPart0(torso);
			leftHip->setPart0(torso);
			neck->setPart0(torso);

			rightShoulder->setPart1(rightArm);
			leftShoulder->setPart1(leftArm);
			rightHip->setPart1(rightLeg);
			leftHip->setPart1(leftLeg);
			neck->setPart1(head);

			G3D::Matrix3 xPos = normalIdToMatrix3(NORM_X);
			G3D::Matrix3 xNeg = normalIdToMatrix3(NORM_X_NEG);
			G3D::Matrix3 yPos = normalIdToMatrix3(NORM_Y);

			G3D::CoordinateFrame rightShoulderP(xPos, G3D::Vector3(1.0f, 0.5f, 0.0f));
			G3D::CoordinateFrame leftShoulderP(xNeg, G3D::Vector3(-1.0f, 0.5f, 0.0f));
			G3D::CoordinateFrame rightHipP(xPos, G3D::Vector3(1.0f, -1.0f, 0.0f));
			G3D::CoordinateFrame leftHipP(xNeg, G3D::Vector3(-1.0f, -1.0f, 0.0f));
			G3D::CoordinateFrame neckP(yPos, G3D::Vector3(0.0f, 1.0f, 0.0f));

			G3D::CoordinateFrame rightArmP(xPos, G3D::Vector3(-0.5f, 0.5f, 0.0f));
			G3D::CoordinateFrame leftArmP(xNeg, G3D::Vector3(0.5f, 0.5f, 0.0f));
			G3D::CoordinateFrame rightLegP(xPos, G3D::Vector3(0.5f, 1.0f, 0.0f));
			G3D::CoordinateFrame leftLegP(xNeg, G3D::Vector3(-0.5f, 1.0f, 0.0f));
			G3D::CoordinateFrame headP(yPos, G3D::Vector3(0.0f, -0.5f, 0.0f));

			rightShoulder->setC0(rightShoulderP);
			leftShoulder->setC0(leftShoulderP);
			rightHip->setC0(rightHipP);
			leftHip->setC0(leftHipP);
			neck->setC0(neckP);

			rightShoulder->setC1(rightArmP);
			leftShoulder->setC1(leftArmP);
			rightHip->setC1(rightLegP);
			leftHip->setC1(leftLegP);
			neck->setC1(headP);

			rightShoulder->setParent(torso);
			leftShoulder->setParent(torso);
			rightHip->setParent(torso);
			leftHip->setParent(torso);
			neck->setParent(torso);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a2f70
// FUNCTION: ROBLOX 0x005eb540
G3D::Vector3 Humanoid::getIntendedMovementVector(bool setWalkMode)
{
	G3D::Vector3 result = G3D::Vector3::zero();

	if (walkMode == DIRECTION_MOVE) {
		result = walkDirection;
	}
	else if (walkMode == CLICK_TO_MOVE) {
		PartInstance* torso = getTorso();
		G3D::Vector3 worldPosition;

		if (torso != NULL && hasWalkToPoint(worldPosition)) {
			const G3D::Vector3& translation = torso->getCoordinateFrame().translation;

			G3D::Vector3 delta = worldPosition - translation;

			worldPosition.x = delta.x;
			worldPosition.y = delta.y + 3.0f;
			worldPosition.z = delta.z;

			float distance = (worldPosition.z * worldPosition.z + worldPosition.x * worldPosition.x) +
							 worldPosition.y * worldPosition.y;

			worldPosition.y = 0;

			if (sqrtf(distance) < 2.0f) {
				if (setWalkMode) {
					walkMode = DIRECTION_MOVE;
				}

				result = G3D::Vector3::zero();
			}
			else {
				result = worldPosition.direction();
			}
		}
	}

	return result;
}

// FUNCTION: WEBSERVICE 0x100a30d0
// FUNCTION: ROBLOX 0x005eb6a0
G3D::Vector3 Humanoid::getIntendedMovementVector()
{
	return getIntendedMovementVector(false);
}

// FUNCTION: WEBSERVICE 0x100a30f0
// FUNCTION: ROBLOX 0x005eb6c0
G3D::Vector3 Humanoid::updateWalkDirection()
{
	return getIntendedMovementVector(true);
}

// FUNCTION: WEBSERVICE 0x100a3110
// FUNCTION: ROBLOX 0x005eb750
static void collectAllDescendantCharacterPrims(
	boost::shared_ptr<Instance> descendent, std::vector<Primitive*>& primitives
)
{
	PartInstance* part = dynamic_cast<PartInstance*>(descendent.get());
	if (part) {
		primitives.push_back(part->getPrimitive());
	}
}

// FUNCTION: WEBSERVICE 0x100a31b0
// FUNCTION: ROBLOX 0x005eb7f0
void Humanoid::tellCameraNear(float distance)
{
	std::vector<Primitive*> primitives;
	if (ModelInstance* character = getCharacterFromHumanoid(this)) {
		character->visitDescendents(boost::bind(&collectAllDescendantCharacterPrims, _1, boost::ref(primitives)));
	}

	float alphaModifier = 1.0f;
	if (distance < 3.0f) {
		alphaModifier = 0.0f;
	}
	else if (distance < 6.0f) {
		alphaModifier = 0.5f;
	}

	for (size_t i = 0; i < primitives.size(); ++i) {
		PartInstance* part = PartInstance::fromPrimitive(primitives[i]);
		if (!dynamic_cast<Tool*>(part->getParent())) {
			part->setAlphaModifier(alphaModifier);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4290
// FUNCTION: ROBLOX 0x005ec930
Humanoid::Humanoid()
	: health(100), maxHealth(100), walkRotationalVelocity(0), walkTimer(0), walkMode(DIRECTION_MOVE), jump(false),
	  imDead(false), hadHeadJoint(false), sit(false), world(NULL)
{
	setName("Humanoid");
}

// FUNCTION: WEBSERVICE 0x100a44c0
// FUNCTION: ROBLOX 0x005ecb60
void Humanoid::onLocalHumanoidEnteringWorkspace()
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);

	if (workspace) {
		if (this == getLocalHumanoidFromContext(this)) {
			if (workspace->getCamera()->getCameraType() == Camera::CUSTOM_CAMERA) {
				if (workspace->getCamera()->getCameraSubject() != this) {
					workspace->getCamera()->setCameraSubject(this);
				}
			}

			if (getHead()) {
				getHead()->setRenderImportance(1.0f);
			}
			if (getLeftLeg()) {
				getLeftLeg()->setRenderImportance(1.0f);
			}
			if (getRightLeg()) {
				getRightLeg()->setRenderImportance(1.0f);
			}
			if (getLeftArm()) {
				getLeftArm()->setRenderImportance(1.0f);
			}
			if (getRightArm()) {
				getRightArm()->setRenderImportance(1.0f);
			}
			if (getTorso()) {
				getTorso()->setRenderImportance(1.0f);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4610
// FUNCTION: ROBLOX 0x005eccb0
void Humanoid::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	stopListening(oldProvider ? oldProvider->create<RunService>() : NULL, this);

	Instance::onServiceProvider(oldProvider, newProvider);

	startListening(newProvider ? newProvider->create<RunService>() : NULL, this);

	if (newProvider && !oldProvider) {
		onLocalHumanoidEnteringWorkspace();
	}
}

// FUNCTION: WEBSERVICE 0x100a4690
// FUNCTION: ROBLOX 0x005ecd30
void Humanoid::renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera)
{
	if (getHead()) {
		Vector3 aboveHead = head->getCoordinateFrame().translation;
		aboveHead.y += 1.5f;

		Vector3 screenLoc = camera.project(aboveHead, adorn->getViewport());
		float distance = (camera.getCoordinateFrame().translation - aboveHead).magnitude();

		if (distance < 100.0f) {
			int fontSize = 8;
			if (distance < 20.0f) {
				fontSize = 12;
			}
			else if (50.0f > distance) {
				fontSize = 10;
			}

			Teams* teams = ServiceProvider::find<Teams>(this);
			G3D::Color3 nameTagColor = teams ? teams->getTeamColorForHumanoid(this) : G3D::Color3::white();

			adorn->drawFont2D(
				getParent()->getName(),
				screenLoc.xy(),
				fontSize,
				G3D::Color4(nameTagColor, 1.0f),
				G3D::Color4(G3D::Color3::black(), 1.0f),
				Adorn::XALIGN_CENTER,
				Adorn::YALIGN_BOTTOM,
				Adorn::PROPORTIONAL_SPACING
			);

			float width = fontSize * 4;
			float height = fontSize / 2;
			G3D::Vector2 low(screenLoc.x - 0.5f * width, screenLoc.y);
			Rect fullRect = Rect::fromLowSize(low, G3D::Vector2(width, height));
			float mid = fullRect.low.x + (health / maxHealth) * width;

			Rect greenRect(fullRect.low.x, fullRect.low.y, mid, fullRect.high.y);
			Rect redRect(mid, fullRect.low.y, fullRect.high.x, fullRect.high.y);

			adorn->rect2d(greenRect.toRect2D(), G3D::Color4(Color::lightGreen(), 1.0f));
			adorn->rect2d(redRect.toRect2D(), G3D::Color4(G3D::Color3::red(), 1.0f));
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4960
// FUNCTION: ROBLOX 0x005ed000
void Humanoid::render2d(Adorn* adorn)
{
	Humanoid* self = this;
	ModelInstance* character = Network::Players::findLocalCharacter(self);
	Humanoid* localHumanoid = character != NULL ? character->findFirstChildOfType<Humanoid>() : NULL;

	if (this == localHumanoid) {
		return;
	}

	Workspace* workspace = Workspace::findWorkspace(self);

	if (workspace != NULL) {
		renderMultiplayer(adorn, workspace->getGCamera());
	}
}

// FUNCTION: WEBSERVICE 0x100a4bf0
// FUNCTION: ROBLOX 0x005ed290
void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
{
	if (ModelInstance* character = getCharacterFromHumanoid(this)) {
		character->visitDescendents(
			boost::bind(
				&collectAllDescendantCharacterPrims, _1, boost::ref(reinterpret_cast<std::vector<Primitive*>&>(ignore))
			)
		);
	}

	ServiceClient<FilteredSelection<PartInstance> > pvSelection(this);
	if (pvSelection) {
		for (std::vector<PartInstance*>::const_iterator iter = pvSelection->begin(); iter != pvSelection->end();
			 ++iter) {
			ignore.push_back((*iter)->getPrimitive());
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4d50
// FUNCTION: ROBLOX 0x005ed3f0
void Humanoid::setHealth(float value)
{
	float newHealth = G3D::clamp(value, 0.0f, maxHealth);

	if (health != newHealth) {
		health = newHealth;
		raisePropertyChanged(propHealth);

		if (health == 0.0f && !imDead) {
			imDead = true;
			setState(new FallingDown(this, Math::inf()));

			if (ModelInstance* character = getCharacterFromHumanoid(this)) {
				character->breakJoints();
			}

			event_Died.fire(this);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4e80
// FUNCTION: ROBLOX 0x005ed520
void Humanoid::setMaxHealth(float value)
{
	if (maxHealth != value) {
		maxHealth = value;
		raisePropertyChanged(propMaxHealth);
	}
}

// FUNCTION: WEBSERVICE 0x100a4eb0
// FUNCTION: ROBLOX 0x005ed550
void Humanoid::takeDamage(float value)
{
	if (getTorso() && !ForceField::partInForceField(getTorso())) {
		setHealth(health - value);
	}
}

// FUNCTION: WEBSERVICE 0x100a4ef0
// FUNCTION: ROBLOX 0x005ed590
void Humanoid::setWalkDirection(const G3D::Vector3& value)
{
	if (walkDirection != value) {
		if (value == G3D::Vector3::zero()) {
			walkDirection = value;
		}
		else {
			walkDirection = G3D::Vector3(value.x, 0.0f, value.z).direction();
			walkMode = DIRECTION_MOVE;
		}

		raisePropertyChanged(propWalkDirection);
	}
}

// FUNCTION: WEBSERVICE 0x100a5000
// FUNCTION: ROBLOX 0x005ed6a0
void Humanoid::setWalkRotationalVelocity(const float& value)
{
	if (walkRotationalVelocity != value) {
		walkRotationalVelocity = value;
		raisePropertyChanged(propWalkRotationalVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x100a5030
// FUNCTION: ROBLOX 0x005ed6d0
void Humanoid::setWalkToPoint(const G3D::Vector3& value)
{
	if (walkToPoint != value) {
		walkToPoint = value;
		raisePropertyChanged(propWalkToPoint);
	}

	walkMode = walkMode == HAS_PART ? CLICK_TO_MOVE : HAS_POINT;
	walkTimer = walkMode == CLICK_TO_MOVE ? 240 : 0;
}

// FUNCTION: WEBSERVICE 0x100a50c0
// FUNCTION: ROBLOX 0x005ed760
void Humanoid::setWalkToPart(PartInstance* value)
{
	if (walkToPart.get() != value) {
		walkToPart = shared_from(value);
		raisePropertyChanged(propWalkToPart);
	}

	walkMode = walkMode == HAS_POINT ? CLICK_TO_MOVE : HAS_PART;
	walkTimer = walkMode == CLICK_TO_MOVE ? 240 : 0;
}

// FUNCTION: WEBSERVICE 0x100a51b0
// FUNCTION: ROBLOX 0x005ed850
void Humanoid::setJump(bool value)
{
	if (jump != value) {
		jump = value;
		raisePropertyChanged(propJump);
	}
}

// FUNCTION: WEBSERVICE 0x100a51f0
// FUNCTION: ROBLOX 0x005ed890
void Humanoid::setSit(bool value)
{
	if (sit != value) {
		sit = value;
		raisePropertyChanged(propSit);
	}
}

// FUNCTION: WEBSERVICE 0x100a5230
// FUNCTION: ROBLOX 0x005ed8d0
void Humanoid::setTargetPoint(const G3D::Vector3& value)
{
	float tolerance = 1.0f;
	if (getTorso()) {
		float torsoToTarget = Math::taxiCabMagnitude(getTorso()->getCoordinateFrame().translation - value);
		tolerance = std::max(2.0f, torsoToTarget) * 0.01f;
	}

	if (Math::taxiCabMagnitude(value - targetPoint) > tolerance) {
		targetPoint = value;
		raisePropertyChanged(propTargetPoint);
	}
}

// FUNCTION: WEBSERVICE 0x100a5310
// FUNCTION: ROBLOX 0x005ed9b0
void Humanoid::moveTo(const G3D::Vector3& worldPosition, PartInstance* part)
{
	if (part) {
		G3D::Vector3 local = part->getCoordinateFrame().pointToObjectSpace(worldPosition);
		walkToPoint = local + G3D::Vector3::unitX();
		walkToPart.reset();

		setWalkToPart(part);
		setWalkToPoint(local);
	}
}

// FUNCTION: WEBSERVICE 0x100a5400
// FUNCTION: ROBLOX 0x005edaa0
void Humanoid::setLeftLeg(PartInstance* value)
{
	if (leftLeg.get() != value) {
		leftLeg = shared_from(value);
		raisePropertyChanged(propLeftLeg);
	}
}

// FUNCTION: WEBSERVICE 0x100a54c0
// FUNCTION: ROBLOX 0x005edb60
void Humanoid::setRightLeg(PartInstance* value)
{
	if (rightLeg.get() != value) {
		rightLeg = shared_from(value);
		raisePropertyChanged(propRightLeg);
	}
}

// FUNCTION: WEBSERVICE 0x100a5580
// FUNCTION: ROBLOX 0x005edc20
void Humanoid::setTorso(PartInstance* value)
{
	if (torso.get() != value) {
		torso = shared_from(value);
		raisePropertyChanged(propTorso);
	}
}

// FUNCTION: WEBSERVICE 0x100a5640
// FUNCTION: ROBLOX 0x005edce0
void Humanoid::checkForJointDeath()
{
	if (Primitive* headPrim = getHeadPrimitive()) {
		if (Primitive* torsoPrim = getTorsoPrimitive()) {
			Joint* joint = headPrim->getFirstJoint();
			while (joint) {
				if (joint->otherPrimitive(headPrim) == torsoPrim) {
					hadHeadJoint = true;
					return;
				}

				joint = headPrim->getNextJoint(joint);
			}
		}
	}

	if (hadHeadJoint) {
		setHealth(0.0f);
	}
}

// FUNCTION: WEBSERVICE 0x100a56c0
// FUNCTION: ROBLOX 0x005edd60
void Humanoid::onEvent(const RunService* source, Stepped event)
{
	if (State* state = currentState.get()) {
		if (getParent()) {
			setState(state->onStep(event.step, *static_cast<PVInstance*>(getParent())->getTopPVController()));
		}
	}

	if (getTorsoPrimitive()) {
		getTorsoPrimitive()->setCanSleep(false);
	}

	checkForJointDeath();

	if (walkTimer > 0) {
		walkTimer--;
		if (walkTimer == 0) {
			walkMode = DIRECTION_MOVE;
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a5770
// FUNCTION: ROBLOX 0x005ede10
void Humanoid::cameraSetWalkOrientation(float rad, bool noAdjust)
{
	if (noAdjust) {
		setWalkRotationalVelocity(0.0f);
	}
	else if (Body* torsoBody = getTorsoBody()) {
		if (Body* root = torsoBody->getRoot()) {
			G3D::Vector3 look = root->getPV().position.lookVector();
			look.y = 0.0f;
			look.unitize();
			float lookAng = Math::radWrap(Math::angleToE0(G3D::Vector2(look.z, look.x)));
			float delta = Math::radWrap(Math::radWrap(rad) - lookAng);
			if (fabs(delta) < 0.1f) {
				delta = 0.0f;
			}
			setWalkRotationalVelocity(delta);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a58a0
// FUNCTION: ROBLOX 0x005edf40
void Humanoid::moveTo2(G3D::Vector3 worldPosition, boost::shared_ptr<Instance> part)
{
	PartInstance* p = dynamic_cast<PartInstance*>(part.get());
	if (!p) {
		throw std::runtime_error("Argument error: A Part is required");
	}

	moveTo(worldPosition, p);
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
bool Humanoid::isControllable() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
bool Humanoid::shouldRender2d() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
bool Humanoid::shouldRender3dAdorn() const
{
	return true;
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>;
template class RBX::Reflection::
	Described<RBX::Humanoid, RBX::sHumanoid, RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid> >;
template class RBX::DescribedCreatable<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>;
