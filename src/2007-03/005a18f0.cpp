// from server: 73% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Humanoid.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Humanoid.h"

#include "network/Players.h"
#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "util/Color.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Workspace.h"
#include "v8kernel/Body.h"
#include "v8tree/Service.h"
#include "v8world/World.h"

namespace RBX {

char sHumanoid[] = "Humanoid";

using namespace Reflection;

static PropDescriptor<Humanoid, float> propMaxHealth(
	"MaxHealth",
	"Game",
	&RBX::Humanoid::getMaxHealth,
	&RBX::Humanoid::setMaxHealth
);

static PropDescriptor<Humanoid, float> propWalkRotationalVelocity(
	"WalkRotationalVelocity",
	"Control",
	&RBX::Humanoid::getWalkRotationalVelocity,
	&RBX::Humanoid::setWalkRotationalVelocity,
	Reflection::PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, bool> propJump(
	"Jump",
	"Control",
	&RBX::Humanoid::getJump,
	&RBX::Humanoid::setJump,
	Reflection::PropertyDescriptor::STREAMING
);

static PropDescriptor<Humanoid, bool> propSit(
	"Sit",
	"Control",
	&RBX::Humanoid::getSit,
	&RBX::Humanoid::setSit,
	Reflection::PropertyDescriptor::STREAMING
);

SignalDesc<Humanoid, void()> Humanoid::event_Died("Died");
SignalDesc<Humanoid, void(float)> Humanoid::event_Running("Running", "speed");
SignalDesc<Humanoid, void(float)> Humanoid::event_Climbing("Climbing", "speed");
SignalDesc<Humanoid, void(bool)> Humanoid::event_Jumping("Jumping", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_FreeFalling("FreeFalling", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_GettingUp("GettingUp", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_FallingDown("FallingDown", "active");
SignalDesc<Humanoid, void(bool)> Humanoid::event_Seated("Seated", "active");

// FUNCTION: WEBSERVICE 0x100a0990
ContactManager* Humanoid::getContactManager()
{
	World* world = Workspace::getWorldIfInWorkspace(this);

	if (world != NULL) {
		return world->getContactManager();
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a0bd0
bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
{
	if (walkToPart != NULL && Workspace::findWorkspace(this) != NULL &&
		Workspace::contextInWorkspace(walkToPart.get())) {
		worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);

		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100a0d40
void Humanoid::computeForce(float dt, bool throttling)
{
	if (currentState.get() != NULL) {
		currentState->onComputeForce(dt);
	}
}

// FUNCTION: WEBSERVICE 0x100a1100
Humanoid::~Humanoid()
{
}

// FUNCTION: WEBSERVICE 0x100a1480
float Humanoid::getIntendedRotationAboutYAxis()
{
	if (currentState.get() != NULL) {
		return currentState->getIntendedRotationAboutYAxis();
	}

	return 0;
}

// STUB: WEBSERVICE 0x100a1b00
void Humanoid::render3dAdorn(Adorn* adorn)
{
	STUB(0x100a1b00);
}

// FUNCTION: WEBSERVICE 0x100a2010
PartInstance* Humanoid::getHead() const
{
	if (head == NULL && getParent() != NULL) {
		head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));
	}

	return head.get();
}

// FUNCTION: WEBSERVICE 0x100a2110
PartInstance* Humanoid::getTorso() const
{
	if (torso == NULL && getParent() != NULL) {
		torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));
	}

	return torso.get();
}

// FUNCTION: WEBSERVICE 0x100a2210
PartInstance* Humanoid::getLeftLeg() const
{
	if (leftLeg == NULL && getParent() != NULL) {
		leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
	}

	return leftLeg.get();
}

// FUNCTION: WEBSERVICE 0x100a2310
PartInstance* Humanoid::getRightLeg() const
{
	if (rightLeg == NULL && getParent() != NULL) {
		rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));
	}

	return rightLeg.get();
}

// FUNCTION: WEBSERVICE 0x100a2410
PartInstance* Humanoid::getLeftArm() const
{
	if (leftArm == NULL && getParent() != NULL) {
		leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));
	}

	return leftArm.get();
}

// FUNCTION: WEBSERVICE 0x100a2510
PartInstance* Humanoid::getRightArm() const
{
	if (rightArm == NULL && getParent() != NULL) {
		rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));
	}

	return rightArm.get();
}

// FUNCTION: WEBSERVICE 0x100a26a0
Primitive* Humanoid::getTorsoPrimitive() const
{
	PartInstance* part = getTorso();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a26c0
Primitive* Humanoid::getLeftLegPrimitive()
{
	PartInstance* part = getLeftLeg();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a26e0
Primitive* Humanoid::getRightLegPrimitive()
{
	PartInstance* part = getRightLeg();

	return part != NULL ? part->getPrimitive() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a2700
Body* Humanoid::getTorsoBody()
{
	PartInstance* part = getTorso();

	return part != NULL ? part->getPrimitive()->getBody() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a2720
Body* Humanoid::getRootBody()
{
	Body* body = getTorsoBody();

	return body != NULL ? body->getRoot() : NULL;
}

// FUNCTION: WEBSERVICE 0x100a27c0
const CoordinateFrame Humanoid::getLocation() const
{
	return getHead() != NULL ? getHead()->getCoordinateFrame() : CoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x100a2f70
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
				result = worldPosition.unit();
			}
		}
	}

	return result;
}

// FUNCTION: WEBSERVICE 0x100a30d0
G3D::Vector3 Humanoid::getIntendedMovementVector()
{
	return getIntendedMovementVector(false);
}

// STUB: WEBSERVICE 0x100a30f0
G3D::Vector3 Humanoid::updateWalkDirection()
{
	STUB(0x100a30f0);
	return G3D::Vector3::zero();
}

// STUB: WEBSERVICE 0x100a31b0
void Humanoid::tellCameraNear(float distance)
{
	STUB(0x100a31b0);
}

// FUNCTION: WEBSERVICE 0x100a4290
Humanoid::Humanoid()
	: health(100), maxHealth(100), walkRotationalVelocity(0), walkTimer(0), walkMode(DIRECTION_MOVE), jump(false),
	  imDead(false), hadHeadJoint(false), sit(false), world(NULL)
{
	setName("Humanoid");
}

// STUB: WEBSERVICE 0x100a4690
void Humanoid::renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera)
{
	if (getHead() != NULL) {
		const CoordinateFrame& headCoord = head->getCoordinateFrame();

		Vector3 headPosition(headCoord.translation.x, headCoord.translation.y + 1.5f, headCoord.translation.z);

		Vector3 projected = camera.project(headPosition, adorn->getViewport());

		float distance = (camera.getCoordinateFrame().translation - headPosition).magnitude();

		if (distance < 100.0f) {
			int fontSize = 8;

			if (20.0f <= distance) {
				if (distance < 50.0f) {
					fontSize = 10;
				}
			}
			else {
				fontSize = 12;
			}

			Teams* teams = ServiceProvider::find<Teams>(this);

			G3D::Color3 nameColor = teams == NULL ? G3D::Color3::white() : teams->getTeamColorForHumanoid(this);

			adorn->drawFont2D(
				getName(),
				projected.xy(),
				fontSize,
				G3D::Color4(nameColor, 1.0f),
				G3D::Color4(G3D::Color3::black(), 1.0f),
				Adorn::XALIGN_CENTER,
				Adorn::YALIGN_CENTER,
				Adorn::PROPORTIONAL_SPACING
			);

			float width = (float) (fontSize * 4);

			headPosition.x -= 0.5f * width;

			Vector2 barLow(headPosition.x, headPosition.y);
			Vector2 barHigh(headPosition.x + width, headPosition.y + (float) (fontSize / 2));

			Vector2 healthHigh(headPosition.x + (health / maxHealth) * width, headPosition.y);

			adorn->rect2d(G3D::Rect2D::xyxy(barLow, healthHigh), G3D::Color4(Color::lightGreen(), 1.0f));
			adorn->rect2d(G3D::Rect2D::xyxy(healthHigh, barHigh), G3D::Color4(G3D::Color3::red(), 1.0f));
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a4960
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

// STUB: WEBSERVICE 0x100a4bf0
void Humanoid::getIgnorePrims(std::vector<const Primitive*>& ignore)
{
	STUB(0x100a4bf0);
}

// FUNCTION: WEBSERVICE 0x100a4e80
void Humanoid::setMaxHealth(float value)
{
	if (maxHealth != value) {
		maxHealth = value;
		raisePropertyChanged(propMaxHealth);
	}
}

// FUNCTION: WEBSERVICE 0x100a5000
void Humanoid::setWalkRotationalVelocity(const float& value)
{
	if (walkRotationalVelocity != value) {
		walkRotationalVelocity = value;
		raisePropertyChanged(propWalkRotationalVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x100a51b0
void Humanoid::setJump(bool value)
{
	if (jump != value) {
		jump = value;
		raisePropertyChanged(propJump);
	}
}

// FUNCTION: WEBSERVICE 0x100a51f0
void Humanoid::setSit(bool value)
{
	if (sit != value) {
		sit = value;
		raisePropertyChanged(propSit);
	}
}

// STUB: WEBSERVICE 0x100a56c0
void Humanoid::onEvent(const RunService* source, Stepped event)
{
	State* state = currentState.get();

	if (state != NULL && getParent() != NULL) {
		State* next = state->onStep(event.step, *static_cast<PVInstance*>(getParent())->getTopPVController());

		if (next != state) {
			currentState.reset(next);
		}
	}
}

// STUB: WEBSERVICE 0x100a5770
void Humanoid::cameraSetWalkOrientation(float rad, bool noAdjust)
{
	STUB(0x100a5770);
}

bool Humanoid::isControllable() const
{
	STUB(0x100e6150);
	return false;
}

bool Humanoid::shouldRender2d() const
{
	STUB(0x100e6151);
	return false;
}

bool Humanoid::shouldRender3dAdorn() const
{
	STUB(0x100e6152);
	return false;
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>;
template class RBX::Reflection::
	Described<RBX::Humanoid, RBX::sHumanoid, RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid> >;
template class RBX::DescribedCreatable<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>;
