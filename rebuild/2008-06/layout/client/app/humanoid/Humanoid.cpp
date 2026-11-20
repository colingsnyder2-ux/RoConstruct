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
}

template class boost::shared_ptr<RBX::AutoJoint>;

#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "humanoid/HumanoidState.h"

namespace RBX {
namespace HUMAN {

bool HumanoidState::canTransition(int event)
{
    switch (event)
    {
    case 0:  return humanoid->imDead;
    case 1:  return humanoid->getJump();
    case 4:  return humanoid->getSit();
    case 5:  return !humanoid->getSit();
    case 6:  return tipped();
    case 7:  return upright();
    case 8:  return floorFound;
    case 9:  return !floorFound;
    case 2:  return humanoid->getStrafe();
    case 3:  return !humanoid->getStrafe();
    case 11: return floorPart.get() != NULL;
    case 10: return floorPart.get() == NULL;
    case 12: return onFloorStep();
    case 13: return !onFloorStep();
    case 15: return value0c <= 0.0f;
    case 14: return flag11;
    case 16: return sub_00643eb0();
    default: return false;
    }
}

}
}
