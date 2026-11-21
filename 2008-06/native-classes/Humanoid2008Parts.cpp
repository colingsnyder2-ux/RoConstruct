// 2008-06 native RBX::Humanoid (inactive), second translation unit of the original Humanoid unit: the bodies that
// need a complete PartInstance. The native v8datamodel/PartInstance.h reaches the donor v8kernel/Connector.h (through
// v8world/Primitive.h), which cannot share a translation unit with v8kernel/Connector2008.h, so this file selects the
// donor Connector for the Humanoid base (NATIVE_HUMANOID2008_DONOR_CONNECTOR, see Humanoid2008.h). Only bodies and the
// four reference-property descriptors live here (no constructor, so no vtable is emitted): the Humanoid layout is the
// same with either Connector (vptr + KernelIndex), and every vtable is built and checked from Humanoid2008.cpp. The two
// virtual bodies here (getContactManager, getLocation) do not depend on Connector slot order. The recorder builds this unit
// with native-headers/engine-world ahead of the donor dirs (the 2008 World: contactManager at +0x84).
// Verified by tests/record_native_humanoid2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "util/NativeContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ForceField.h"
#include "humanoid/Humanoid2008.h"
#include "util/Object.h"
#include "util/Math.h"
#include <stdexcept>
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/JointInstance.h"
#include "util/NormalId.h"            // normalIdToMatrix3 005ec800 (buildJoints 005d9340)
#include "v8datamodel/Workspace.h"   // native (read only): findWorkspace 005a3380, contextInWorkspace 005a33d0

namespace RBX
{
	extern Reflection::PropDescriptor<Humanoid, G3D::Vector3> propTargetPoint;   // Humanoid2008.cpp (0097a4b0), setTargetPoint

	Reflection::RefPropDescriptor<Humanoid, PartInstance> propTorso("Torso", "Data", &Humanoid::getTorso, &Humanoid::setTorso, Reflection::PropertyDescriptor::UI);                // 0097a538
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propLeftLeg("LeftLeg", "Data", &Humanoid::getLeftLeg, &Humanoid::setLeftLeg, Reflection::PropertyDescriptor::UI);        // 0097a3b0
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propRightLeg("RightLeg", "Data", &Humanoid::getRightLeg, &Humanoid::setRightLeg, Reflection::PropertyDescriptor::UI);    // 0097a5dc
	Reflection::RefPropDescriptor<Humanoid, PartInstance> propWalkToPart("WalkToPart", "Control", &Humanoid::getWalkToPart, &Humanoid::setWalkToPart, Reflection::PropertyDescriptor::STREAMING); // 0097a328

	PartInstance* Humanoid::getHead() const
	{
		if (!head && getParent())
			head = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Head"));

		return head.get();
	}

	PartInstance* Humanoid::getTorso() const
	{
		if (!torso && getParent())
			torso = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));

		return torso.get();
	}

	PartInstance* Humanoid::getLeftLeg() const
	{
		if (!leftLeg && getParent())
			leftLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));

		return leftLeg.get();
	}

	PartInstance* Humanoid::getRightLeg() const
	{
		if (!rightLeg && getParent())
			rightLeg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));

		return rightLeg.get();
	}

	PartInstance* Humanoid::getLeftArm() const
	{
		if (!leftArm && getParent())
			leftArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));

		return leftArm.get();
	}

	PartInstance* Humanoid::getRightArm() const
	{
		if (!rightArm && getParent())
			rightArm = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));

		return rightArm.get();
	}

	void Humanoid::takeDamage(float amount)
	{
		if (getTorso() && !ForceField::isProtected(getTorso()))
			setHealth(health - amount);
	}

	void Humanoid::setWalkToPart(PartInstance* value)
	{
		if (walkToPart.get() != value)
		{
			walkToPart = shared_from(value);
			raisePropertyChanged(propWalkToPart);
		}

		walkMode = (walkMode == HAS_POINT) ? CLICK_TO_MOVE : HAS_PART;
		walkTimer = (walkMode == CLICK_TO_MOVE) ? 240 : 0;
	}

	void Humanoid::setLeftLeg(PartInstance* value)
	{
		if (leftLeg.get() != value)
		{
			leftLeg = shared_from(value);
			raisePropertyChanged(propLeftLeg);
		}
	}

	void Humanoid::setRightLeg(PartInstance* value)
	{
		if (rightLeg.get() != value)
		{
			rightLeg = shared_from(value);
			raisePropertyChanged(propRightLeg);
		}
	}

	void Humanoid::setTorso(PartInstance* value)
	{
		if (torso.get() != value)
		{
			torso = shared_from(value);
			raisePropertyChanged(propTorso);
		}
	}

	ContactManager* Humanoid::getContactManager()
	{
		return world ? &world->getContactManager() : NULL;
	}

	void Humanoid::moveTo2(G3D::Vector3 worldPosition, boost::shared_ptr<Instance> part)
	{
		PartInstance* p = dynamic_cast<PartInstance*>(part.get());
		if (!p)
			throw std::runtime_error("Argument error: A Part is required");

		moveTo(worldPosition, p);
	}

	const G3D::CoordinateFrame Humanoid::getLocation() const
	{
		return getHead() ? getHead()->getCoordinateFrame() : G3D::CoordinateFrame();
	}

	void Humanoid::moveTo(const G3D::Vector3& worldPosition, PartInstance* part)
	{
		if (part)
		{
			G3D::Vector3 local = part->getCoordinateFrame().pointToObjectSpace(worldPosition);

			walkToPoint = local + G3D::Vector3::unitX();
			walkToPart.reset();
			setWalkToPart(part);
			setWalkToPoint(local);
		}
	}

	void Humanoid::setTargetPoint(const G3D::Vector3& value)
	{
		float tolerance = 1.0f;
		if (getTorso())
		{
			float distance = Math::taxiCabMagnitude(getTorso()->getCoordinateFrame().translation - value);
			tolerance = std::max(2.0f, distance) * 0.01f;
		}

		if (Math::taxiCabMagnitude(value - targetPoint) > tolerance)
		{
			targetPoint = value;
			raisePropertyChanged(propTargetPoint);
		}
	}

	// 005d79b0: Workspace::findWorkspace 005a3380 / contextInWorkspace 005a33d0 (native v8datamodel/Workspace.h).
	bool Humanoid::hasWalkToPoint(G3D::Vector3& worldPosition) const
	{
		if (walkToPart && Workspace::findWorkspace(this) && Workspace::contextInWorkspace(walkToPart.get()))
		{
			worldPosition = walkToPart->getCoordinateFrame().pointToWorldSpace(walkToPoint);
			return true;
		}
		else
		{
			return false;
		}
	}

	PartInstance* Humanoid::getHeadFromCharacter(const ModelInstance* character)
	{
		return character ? dynamic_cast<PartInstance*>(character->findFirstChildByName("Head")) : NULL;
	}

	JointInstance* Humanoid::findRightShoulder() const
	{
		PartInstance* torso = getTorso();
		return torso ? rbx_static_cast<JointInstance*>(torso->findFirstChildByName("Right Shoulder")) : NULL;
	}

	// 005d8420. Free helper of the original unit (buildJoints 005d9340 calls it five times); name and linkage after the
	// donor. Batch 27: returns shared_ptr<JointInstance> because v8datamodel/JointInstance.h now derives Motor and Snap
	// from JointInstance (2008 RTTI), so the donor's shared_ptr<AutoJoint> return no longer compiles (the whole unit
	// failed with C2440). The body has no pointer adjustment either way (bases at offset 0); the registry's
	// decorated name ?newJoint@RBX@@YA?AV?$shared_ptr@VAutoJoint@RBX@@@boost@@_N@Z comes from the donor signature.
	boost::shared_ptr<JointInstance> newJoint(bool animated)
	{
		if (animated)
		{
			boost::shared_ptr<Motor> m = Creatable<Instance>::create<Motor>();
			m->setMaxVelocity(0.1f);
			return m;
		}
		else
		{
			boost::shared_ptr<Snap> s = Creatable<Instance>::create<Snap>();
			return s;
		}
	}

	// INFERRED: newJoint returns shared_ptr<JointInstance> here (batch 27) while the target calls the AutoJoint setters
	// on the same pointers; a no-op downcast (AutoJoint base at offset 0) keeps the limb pointers in registers.
	static inline AutoJoint* asAutoJoint(const boost::shared_ptr<JointInstance>& joint)
	{
		return static_cast<AutoJoint*>(joint.get());
	}

	// 005d9340 (1745 bytes, thiscall; registry placeholder func_005d9340). Donor tools/rbxgs humanoid/Humanoid.cpp
	// buildJoints without the RBXASSERTs and without the six Body::setCanThrottle(false) calls (the 2008 body goes from
	// the limb getters 005d8a10 / 005d8b10 / 005d8f10 / 005d8e10 / 005d8d10 / 005d8c10 straight to newJoint 005d8420).
	// getCharacterFromHumanoid 005d7670 is inlined in the target (this != NULL, dynamic_cast of parent +0x104 to
	// ModelInstance) while this header declares it out of line: the inline test below copies that body (INFERRED).
	// newJoint returns shared_ptr<JointInstance> here (batch 27); the target calls AutoJoint::setPart0 005e4450,
	// setPart1 005e4470, setC0 005e4490, setC1 005e44c0 on the same pointers (static_cast, base at offset 0), the
	// virtual setName (Instance slot 1) and Instance::setParent 0055a8f0; normalIdToMatrix3 005ec800 into Matrix3 copies.
	void Humanoid::buildJoints()
	{
		ModelInstance* character = this ? dynamic_cast<ModelInstance*>(getParent()) : NULL;
		if (!character)
			return;

		PartInstance* head = getHead();
		PartInstance* torso = getTorso();
		PartInstance* rightArm = getRightArm();
		PartInstance* leftArm = getLeftArm();
		PartInstance* rightLeg = getRightLeg();
		PartInstance* leftLeg = getLeftLeg();

		if (!torso)
			return;

		boost::shared_ptr<JointInstance> rightShoulder = newJoint(true);
		boost::shared_ptr<JointInstance> leftShoulder = newJoint(true);
		boost::shared_ptr<JointInstance> rightHip = newJoint(true);
		boost::shared_ptr<JointInstance> leftHip = newJoint(true);
		boost::shared_ptr<JointInstance> neck = newJoint(false);

		rightShoulder->setName("Right Shoulder");
		leftShoulder->setName("Left Shoulder");
		rightHip->setName("Right Hip");
		leftHip->setName("Left Hip");
		neck->setName("Neck");

		asAutoJoint(rightShoulder)->setPart0(torso);
		asAutoJoint(leftShoulder)->setPart0(torso);
		asAutoJoint(rightHip)->setPart0(torso);
		asAutoJoint(leftHip)->setPart0(torso);
		asAutoJoint(neck)->setPart0(torso);

		asAutoJoint(rightShoulder)->setPart1(rightArm);
		asAutoJoint(leftShoulder)->setPart1(leftArm);
		asAutoJoint(rightHip)->setPart1(rightLeg);
		asAutoJoint(leftHip)->setPart1(leftLeg);
		asAutoJoint(neck)->setPart1(head);

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

		asAutoJoint(rightShoulder)->setC0(rightShoulderP);
		asAutoJoint(leftShoulder)->setC0(leftShoulderP);
		asAutoJoint(rightHip)->setC0(rightHipP);
		asAutoJoint(leftHip)->setC0(leftHipP);
		asAutoJoint(neck)->setC0(neckP);

		asAutoJoint(rightShoulder)->setC1(rightArmP);
		asAutoJoint(leftShoulder)->setC1(leftArmP);
		asAutoJoint(rightHip)->setC1(rightLegP);
		asAutoJoint(leftHip)->setC1(leftLegP);
		asAutoJoint(neck)->setC1(headP);

		rightShoulder->setParent(torso);
		leftShoulder->setParent(torso);
		rightHip->setParent(torso);
		leftHip->setParent(torso);
		neck->setParent(torso);
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::AutoJoint>;
