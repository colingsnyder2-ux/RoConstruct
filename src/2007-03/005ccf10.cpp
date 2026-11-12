// from server: 86% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/JointInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/JointInstance.h"

#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "util/Math.h"
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

namespace RBX {

const char sAutoJoint[] = "AutoJoint";

const char sJointInstance[] = "JointInstance";

const char sMotor[] = "Motor";

const char sRotateV[] = "RotateV";

const char sRotateP[] = "RotateP";

const char sRotate[] = "Rotate";

const char sGlue[] = "Glue";

const char sWeld[] = "Weld";

const char sSnap[] = "Snap";

} // namespace RBX

using namespace RBX;

static Reflection::RefPropDescriptor<AutoJoint, PartInstance> prop_Part0(
	"Part0", "Data", &RBX::AutoJoint::getPart0, &RBX::AutoJoint::setPart0
);

static Reflection::RefPropDescriptor<AutoJoint, PartInstance> prop_Part1(
	"Part1", "Data", &RBX::AutoJoint::getPart1, &RBX::AutoJoint::setPart1
);

static Reflection::PropDescriptor<AutoJoint, CoordinateFrame> prop_C1(
	"C1", "Data", &RBX::AutoJoint::getC1, &RBX::AutoJoint::setC1
);

static Reflection::PropDescriptor<AutoJoint, CoordinateFrame> prop_C0(
	"C0", "Data", &RBX::AutoJoint::getC0, &RBX::AutoJoint::setC0
);

static Reflection::PropDescriptor<Motor, float> prop_MaxVelocity(
	"MaxVelocity", "Data", &RBX::Motor::getMaxVelocity, &RBX::Motor::setMaxVelocity
);

static Reflection::PropDescriptor<Motor, float> prop_DesiredAngle(
	"DesiredAngle", "Data", &RBX::Motor::getDesiredAngle, &RBX::Motor::setDesiredAngle
);

static Reflection::PropDescriptor<Motor, float> prop_CurrentAngle(
	"CurrentAngle", "Data", &RBX::Motor::getCurrentAngle, &RBX::Motor::setCurrentAngle
);

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d7a80
// FUNCTION: ROBLOX 0x005f1990
bool JointInstance::shouldRender3dAdorn() const
{
	return PartInstance::showSpanningTree;
}

// FUNCTION: WEBSERVICE 0x100d7a90
const CoordinateFrame& AutoJoint::getC0() const
{
	return joint->getJointCoord(0);
}

// FUNCTION: WEBSERVICE 0x100d7aa0
const CoordinateFrame& AutoJoint::getC1() const
{
	return joint->getJointCoord(1);
}

// FUNCTION: WEBSERVICE 0x100d7bc0
// FUNCTION: ROBLOX 0x005f1ae0
void JointInstance::render3dAdorn(Adorn* adorn)
{
	if (Joint::isAssemblyJoint(joint)) {
		Primitive* p0 = joint->getPrimitive(0);
		Primitive* p1 = joint->getPrimitive(1);

		Vector3 pt0 = p0 ? p0->getCoordinateFrame().translation : Vector3::zero();
		Vector3 pt1 = p1 ? p1->getCoordinateFrame().translation : Vector3::zero();

		Color3 color = joint->getActive() ? Color3::green() : Color3::red();

		adorn->setObjectToWorldMatrix(CoordinateFrame());

		adorn->lineSegment(G3D::LineSegment::fromTwoPoints(pt0, pt1), color, 20.0f);
	}
}

// FUNCTION: WEBSERVICE 0x100d7d70 FOLDED
float Motor::getMaxVelocity() const
{
	return getMotorJoint()->maxVelocity;
}

// FUNCTION: WEBSERVICE 0x100d7d80 FOLDED
float Motor::getDesiredAngle() const
{
	return getMotorJoint()->desiredAngle;
}

// FUNCTION: WEBSERVICE 0x100d7df0
// FUNCTION: ROBLOX 0x005f1d10
JointInstance::~JointInstance()
{
	joint->setJointOwner(NULL);
	delete joint;
	joint = NULL;
}

// FUNCTION: WEBSERVICE 0x100d8030
// FUNCTION: ROBLOX 0x005f1f60
void AutoJoint::setPart(int i, PartInstance* value)
{
	if (part[i].get() == value) {
		return;
	}

	part[i] = shared_from(value);
	joint->setPrimitive(i, value ? value->getPrimitive() : NULL);
}

// FUNCTION: WEBSERVICE 0x100d8110
// FUNCTION: ROBLOX 0x005f2040
AutoJoint::~AutoJoint()
{
	setPart(0, NULL);
	setPart(1, NULL);
}

// FUNCTION: WEBSERVICE 0x100d8a00
// FUNCTION: ROBLOX 0x005f28c0
bool AutoJoint::askSetParent(const Instance* instance) const
{
	return instance->getDescriptor() == Instance::classDescriptor() ||
		   instance->getDescriptor() == PartInstance::classDescriptor();
}

// FUNCTION: WEBSERVICE 0x100d8ad0
// FUNCTION: ROBLOX 0x005f2990
JointInstance::JointInstance(Joint* joint) : joint(joint)
{
	joint->setJointOwner(this);
}

World* AutoJoint::computeWorld()
{
	if (getParent() != NULL && getParent()->getDescriptor() == Instance::classDescriptor()) {
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		return workspace ? workspace->getWorld() : NULL;
	}

	return Workspace::getWorldIfInWorkspace(this);
}

// FUNCTION: WEBSERVICE 0x100d8b90
// FUNCTION: ROBLOX 0x005f2a50
void AutoJoint::onAncestorChanged(const AncestorChanged& event)
{
	Instance::onAncestorChanged(event);

	World* oldWorld = joint->getWorld();
	World* newWorld = computeWorld();

	if (oldWorld != newWorld) {
		if (oldWorld) {
			oldWorld->removeJoint(joint);
		}

		if (newWorld) {
			newWorld->insertJoint(joint);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d8de0
// FUNCTION: ROBLOX 0x005f2c90
AutoJoint::AutoJoint(Joint* _joint) : DescribedNonCreatable<AutoJoint, JointInstance, sAutoJoint>(_joint)
{
	PartInstance* p0 = const_cast<PartInstance*>(PartInstance::fromPrimitiveConst(joint->getPrimitive(0)));
	PartInstance* p1 = const_cast<PartInstance*>(PartInstance::fromPrimitiveConst(joint->getPrimitive(1)));
	part[0] = shared_from(p0);
	part[1] = shared_from(p1);
}

// FUNCTION: WEBSERVICE 0x100d8f80
// FUNCTION: ROBLOX 0x005f2e30
void AutoJoint::setPart0(PartInstance* value)
{
	setPart(0, value);
	raisePropertyChanged(prop_Part0);
}

// FUNCTION: WEBSERVICE 0x100d8fa0
// FUNCTION: ROBLOX 0x005f2e50
void AutoJoint::setPart1(PartInstance* value)
{
	setPart(1, value);
	raisePropertyChanged(prop_Part1);
}

// FUNCTION: WEBSERVICE 0x100d8fc0
// FUNCTION: ROBLOX 0x005f2e70
void AutoJoint::setC0(const CoordinateFrame& value)
{
	joint->setJointCoord(0, value);
	raisePropertyChanged(prop_C0);
}

// FUNCTION: WEBSERVICE 0x100d8ff0
// FUNCTION: ROBLOX 0x005f2ea0
void AutoJoint::setC1(const CoordinateFrame& value)
{
	joint->setJointCoord(1, value);
	raisePropertyChanged(prop_C1);
}

// FUNCTION: WEBSERVICE 0x100d9020
// FUNCTION: ROBLOX 0x005f2ed0
void Motor::setMaxVelocity(float value)
{
	if (value != getMotorJoint()->maxVelocity) {
		getMotorJoint()->maxVelocity = value;
		raisePropertyChanged(prop_MaxVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x100d9060
// FUNCTION: ROBLOX 0x005f2f10
void Motor::setDesiredAngle(float value)
{
	if (!Math::fuzzyEq(value, getMotorJoint()->desiredAngle, 0.034906585f)) {
		getMotorJoint()->desiredAngle = value;
		raisePropertyChanged(prop_DesiredAngle);
	}
}

// FUNCTION: WEBSERVICE 0x100d90c0
void Motor::setCurrentAngle(float value)
{
	if (value != getMotorJoint()->getCurrentAngle()) {
		getMotorJoint()->setCurrentAngle(value);
		raisePropertyChanged(prop_CurrentAngle);
	}
}

// FUNCTION: WEBSERVICE 0x100d9a10
// FUNCTION: ROBLOX 0x005f3920
Snap::Snap(Joint* joint) : DescribedCreatable<Snap, AutoJoint, sSnap>(joint)
{
	setName("Snap");
}

// FUNCTION: WEBSERVICE 0x100d9b20
// FUNCTION: ROBLOX 0x005f3a40
Snap::Snap() : DescribedCreatable<Snap, AutoJoint, sSnap>(new SnapJoint())
{
	setName("Snap");
}

// FUNCTION: WEBSERVICE 0x100d9c20
// FUNCTION: ROBLOX 0x005f3b40
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, AutoJoint, sWeld>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100d9cb0
// FUNCTION: ROBLOX 0x005f3be0
Weld::Weld() : DescribedCreatable<Weld, AutoJoint, sWeld>(new WeldJoint())
{
}

// FUNCTION: WEBSERVICE 0x100d9d80
// FUNCTION: ROBLOX 0x005f3cb0
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, AutoJoint, sGlue>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100d9e00
// FUNCTION: ROBLOX 0x005f3d60
Glue::Glue() : DescribedCreatable<Glue, AutoJoint, sGlue>(new GlueJoint())
{
}

// FUNCTION: WEBSERVICE 0x100d9ec0
// FUNCTION: ROBLOX 0x005f3e20
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, AutoJoint, sRotate>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100d9f90
// FUNCTION: ROBLOX 0x005f3ea0
Rotate::Rotate() : DescribedCreatable<Rotate, AutoJoint, sRotate>(new RotateJoint())
{
}

// FUNCTION: WEBSERVICE 0x100da050
// FUNCTION: ROBLOX 0x005f3f60
RotateP::RotateP(Joint* joint) : DescribedCreatable<RotateP, AutoJoint, sRotateP>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100da100
// FUNCTION: ROBLOX 0x005f4000
RotateP::RotateP() : DescribedCreatable<RotateP, AutoJoint, sRotateP>(new RotatePJoint())
{
}

// FUNCTION: WEBSERVICE 0x100da1d0
// FUNCTION: ROBLOX 0x005f40d0
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, AutoJoint, sRotateV>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100da280
// FUNCTION: ROBLOX 0x005f41a0
RotateV::RotateV() : DescribedCreatable<RotateV, AutoJoint, sRotateV>(new RotateVJoint())
{
}

Motor::Motor(Joint* joint) : DescribedCreatable<Motor, AutoJoint, sMotor>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100da370
// FUNCTION: ROBLOX 0x005f4290
Motor::Motor() : DescribedCreatable<Motor, AutoJoint, sMotor>(new MotorJoint())
{
	setName("Motor");
}

// FUNCTION: WEBSERVICE 0x100e3c30 FOLDED
// FUNCTION: ROBLOX 0x004f1410 FOLDED
PartInstance* AutoJoint::getPart1() const
{
	return part[1].get();
}

// FUNCTION: WEBSERVICE 0x100e42d0 FOLDED
float Motor::getCurrentAngle() const
{
	return getMotorJoint()->getCurrentAngle();
}

// FUNCTION: WEBSERVICE 0x100f9de0 FOLDED
// FUNCTION: ROBLOX 0x006171e0 FOLDED
PartInstance* AutoJoint::getPart0() const
{
	return part[0].get();
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sJointInstance>();
template void RBX::Name::callDoDeclare<RBX::sJointInstance>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sAutoJoint>();
template void RBX::Name::callDoDeclare<RBX::sAutoJoint>();

template class RBX::FactoryProduct<RBX::Glue, RBX::AutoJoint, RBX::sGlue>;
template class RBX::Reflection::
	Described<RBX::Glue, RBX::sGlue, RBX::FactoryProduct<RBX::Glue, RBX::AutoJoint, RBX::sGlue> >;
template class RBX::DescribedCreatable<RBX::Glue, RBX::AutoJoint, RBX::sGlue>;

template class RBX::FactoryProduct<RBX::Rotate, RBX::AutoJoint, RBX::sRotate>;
template class RBX::Reflection::
	Described<RBX::Rotate, RBX::sRotate, RBX::FactoryProduct<RBX::Rotate, RBX::AutoJoint, RBX::sRotate> >;
template class RBX::DescribedCreatable<RBX::Rotate, RBX::AutoJoint, RBX::sRotate>;

template class RBX::FactoryProduct<RBX::RotateP, RBX::AutoJoint, RBX::sRotateP>;
template class RBX::Reflection::
	Described<RBX::RotateP, RBX::sRotateP, RBX::FactoryProduct<RBX::RotateP, RBX::AutoJoint, RBX::sRotateP> >;
template class RBX::DescribedCreatable<RBX::RotateP, RBX::AutoJoint, RBX::sRotateP>;

template class RBX::FactoryProduct<RBX::RotateV, RBX::AutoJoint, RBX::sRotateV>;
template class RBX::Reflection::
	Described<RBX::RotateV, RBX::sRotateV, RBX::FactoryProduct<RBX::RotateV, RBX::AutoJoint, RBX::sRotateV> >;
template class RBX::DescribedCreatable<RBX::RotateV, RBX::AutoJoint, RBX::sRotateV>;

template class RBX::FactoryProduct<RBX::Snap, RBX::AutoJoint, RBX::sSnap>;
template class RBX::Reflection::
	Described<RBX::Snap, RBX::sSnap, RBX::FactoryProduct<RBX::Snap, RBX::AutoJoint, RBX::sSnap> >;
template class RBX::DescribedCreatable<RBX::Snap, RBX::AutoJoint, RBX::sSnap>;

template class RBX::FactoryProduct<RBX::Weld, RBX::AutoJoint, RBX::sWeld>;
template class RBX::Reflection::
	Described<RBX::Weld, RBX::sWeld, RBX::FactoryProduct<RBX::Weld, RBX::AutoJoint, RBX::sWeld> >;
template class RBX::DescribedCreatable<RBX::Weld, RBX::AutoJoint, RBX::sWeld>;
