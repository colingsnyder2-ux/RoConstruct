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
// >>> native-status (generated) -- do not edit >>>
// Humanoid2008Parts | 2008-06 | selection unverified
// 0/18 mapped addresses reported exact (subset) | 7 referenced strings (not rechecked) | historical| by colin (+4) (mixed 6)
// <<< native-status | src 02c79c42 | roc native-status --write
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

	// Free helper of the original unit (buildJoints 005d9340 calls it five times); name and linkage after the donor.
	boost::shared_ptr<AutoJoint> newJoint(bool animated)
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
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::AutoJoint>;
