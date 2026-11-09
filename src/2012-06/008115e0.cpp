// from server: 62% by intel
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/JointInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/JointInstance.h"

#include "reflection/property.h"
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

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

static Reflection::PropDescriptor<Motor, float> prop_MaxVelocity(
	"MaxVelocity",
	"Data",
	&RBX::Motor::getMaxVelocity,
	&RBX::Motor::setMaxVelocity
);

static Reflection::PropDescriptor<Motor, float> prop_CurrentAngle(
	"CurrentAngle",
	"Data",
	&RBX::Motor::getCurrentAngle,
	&RBX::Motor::setCurrentAngle
);

float Motor::getMaxVelocity() const
{
	return static_cast<MotorJoint*>(joint)->getMaxVelocity();
}

float Motor::getCurrentAngle() const
{
	return static_cast<MotorJoint*>(joint)->getCurrentAngle();
}

// FUNCTION: WEBSERVICE 0x100d7df0
JointInstance::~JointInstance()
{
	joint->setJointOwner(NULL);
	delete joint;
	joint = NULL;
}

// STUB: WEBSERVICE 0x100d8030
void AutoJoint::setPart(int index, PartInstance* value)
{
	if (part[index].get() == value) {
		return;
	}

	part[index] = shared_from(value);
	joint->setPrimitive(index, value ? value->getPrimitive() : NULL);
}

// STUB: WEBSERVICE 0x100d8110
AutoJoint::~AutoJoint()
{
	setPart(0, NULL);
	setPart(1, NULL);
}

// FUNCTION: WEBSERVICE 0x100d9020
void Motor::setMaxVelocity(float value)
{
	if (value != static_cast<MotorJoint*>(joint)->getMaxVelocity()) {
		static_cast<MotorJoint*>(joint)->setMaxVelocity(value);
		raisePropertyChanged(prop_MaxVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x100d90c0
void Motor::setCurrentAngle(float value)
{
	if (value != static_cast<MotorJoint*>(joint)->getCurrentAngle()) {
		static_cast<MotorJoint*>(joint)->setCurrentAngle(value);
		raisePropertyChanged(prop_CurrentAngle);
	}
}

Snap::Snap(Joint* joint) : DescribedCreatable<Snap, AutoJoint, sSnap>(joint)
{
}

// STUB: WEBSERVICE 0x100d9b20
Snap::Snap() : DescribedCreatable<Snap, AutoJoint, sSnap>(new SnapJoint())
{
	setName("Snap");
}

// STUB: WEBSERVICE 0x100d9c20
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, AutoJoint, sWeld>(joint)
{
}

// STUB: WEBSERVICE 0x100d9cb0
Weld::Weld() : DescribedCreatable<Weld, AutoJoint, sWeld>(new WeldJoint())
{
}

// FUNCTION: WEBSERVICE 0x100d9d80
Glue::Glue(Joint* joint) : DescribedCreatable<Glue, AutoJoint, sGlue>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100d9e00
Glue::Glue() : DescribedCreatable<Glue, AutoJoint, sGlue>(new GlueJoint())
{
}

// STUB: WEBSERVICE 0x100d9ec0
Rotate::Rotate(Joint* joint) : DescribedCreatable<Rotate, AutoJoint, sRotate>(joint)
{
}

// STUB: WEBSERVICE 0x100d9f90
Rotate::Rotate() : DescribedCreatable<Rotate, AutoJoint, sRotate>(new RotateJoint())
{
}

// STUB: WEBSERVICE 0x100da050
RotateP::RotateP(Joint* joint) : DescribedCreatable<RotateP, AutoJoint, sRotateP>(joint)
{
}

// STUB: WEBSERVICE 0x100da100
RotateP::RotateP() : DescribedCreatable<RotateP, AutoJoint, sRotateP>(new RotatePJoint())
{
}

// STUB: WEBSERVICE 0x100da1d0
RotateV::RotateV(Joint* joint) : DescribedCreatable<RotateV, AutoJoint, sRotateV>(joint)
{
}

// STUB: WEBSERVICE 0x100da280
RotateV::RotateV() : DescribedCreatable<RotateV, AutoJoint, sRotateV>(new RotateVJoint())
{
}

Motor::Motor(Joint* joint) : DescribedCreatable<Motor, AutoJoint, sMotor>(joint)
{
}

// FUNCTION: WEBSERVICE 0x100da370
Motor::Motor() : DescribedCreatable<Motor, AutoJoint, sMotor>(new MotorJoint())
{
	setName("Motor");
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
