// from server: 39% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Feature.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Feature.h"

#include "reflection/property.h"
#include "util/Name.h"

namespace RBX {

const char sVelocityMotor[] = "VelocityMotor";

const char sHole[] = "Hole";

const char sMotorFeature[] = "MotorFeature";

const char sFeature[] = "Feature";

using namespace Reflection;

static EnumPropDescriptor<Feature, NormalId> prop_FaceId(
	"FaceId",
	"Data",
	&RBX::Feature::getFaceId,
	&RBX::Feature::setFaceId
);

static EnumPropDescriptor<Feature, Feature::TopBottom> prop_TopBottom(
	"TopBottom",
	"Data",
	&RBX::Feature::getTopBottom,
	&RBX::Feature::setTopBottom
);

static EnumPropDescriptor<Feature, Feature::LeftRight> prop_LeftRight(
	"LeftRight",
	"Data",
	&RBX::Feature::getLeftRight,
	&RBX::Feature::setLeftRight
);

static EnumPropDescriptor<Feature, Feature::InOut> prop_InOut(
	"InOut",
	"Data",
	&RBX::Feature::getInOut,
	&RBX::Feature::setInOut
);

static PropDescriptor<VelocityMotor, float> prop_MaxVelocity(
	"MaxVelocity",
	"Data",
	&RBX::VelocityMotor::getMaxVelocity,
	&RBX::VelocityMotor::setMaxVelocity
);

static PropDescriptor<VelocityMotor, float> prop_DesiredAngle(
	"DesiredAngle",
	"Data",
	&RBX::VelocityMotor::getDesiredAngle,
	&RBX::VelocityMotor::setDesiredAngle
);

static PropDescriptor<VelocityMotor, float> prop_CurrentAngle(
	"CurrentAngle",
	"Data",
	&RBX::VelocityMotor::getCurrentAngle,
	&RBX::VelocityMotor::setCurrentAngle
);

// FUNCTION: WEBSERVICE 0x100d7d70
float VelocityMotor::getMaxVelocity() const
{
	return static_cast<MotorJoint*>(joint)->getMaxVelocity();
}

// FUNCTION: WEBSERVICE 0x100d7d80
float VelocityMotor::getDesiredAngle() const
{
	return static_cast<MotorJoint*>(joint)->getDesiredAngle();
}

// FUNCTION: WEBSERVICE 0x100e42d0
float VelocityMotor::getCurrentAngle() const
{
	return static_cast<MotorJoint*>(joint)->getCurrentAngle();
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x100e5950
template <>
EnumDesc<Feature::TopBottom>::EnumDesc() : EnumDescriptor("TopBottom", typeid(Feature::TopBottom))
{
	addPair(Feature::TOP, "Top");
	addPair(Feature::CENTER_TB, "Center");
	addPair(Feature::BOTTOM, "Bottom");
}

// FUNCTION: WEBSERVICE 0x100e5ad0
template <>
EnumDesc<Feature::LeftRight>::EnumDesc() : EnumDescriptor("LeftRight", typeid(Feature::LeftRight))
{
	addPair(Feature::LEFT, "Left");
	addPair(Feature::CENTER_LR, "Center");
	addPair(Feature::RIGHT, "Right");
}

// FUNCTION: WEBSERVICE 0x100e5c50
template <>
EnumDesc<Feature::InOut>::EnumDesc() : EnumDescriptor("InOut", typeid(Feature::InOut))
{
	addPair(Feature::EDGE, "Edge");
	addPair(Feature::INSET, "Inset");
	addPair(Feature::CENTER_IO, "Center");
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x100e7430
void Feature::setFaceId(NormalId value)
{
	if (faceId != value) {
		faceId = value;
		raisePropertyChanged(prop_FaceId);
	}
}

// FUNCTION: WEBSERVICE 0x100e7460
void Feature::setTopBottom(TopBottom value)
{
	if (topBottom != value) {
		topBottom = value;
		raisePropertyChanged(prop_TopBottom);
	}
}

// FUNCTION: WEBSERVICE 0x100e7490
void Feature::setLeftRight(LeftRight value)
{
	if (leftRight != value) {
		leftRight = value;
		raisePropertyChanged(prop_LeftRight);
	}
}

// FUNCTION: WEBSERVICE 0x100e74c0
void Feature::setInOut(InOut value)
{
	if (inOut != value) {
		inOut = value;
		raisePropertyChanged(prop_InOut);
	}
}

// FUNCTION: WEBSERVICE 0x100e7670
void VelocityMotor::setMaxVelocity(float value)
{
	if (value != static_cast<MotorJoint*>(joint)->getMaxVelocity()) {
		static_cast<MotorJoint*>(joint)->setMaxVelocity(value);
		raisePropertyChanged(prop_MaxVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x100e76b0
void VelocityMotor::setDesiredAngle(float value)
{
	if (value != static_cast<MotorJoint*>(joint)->getDesiredAngle()) {
		static_cast<MotorJoint*>(joint)->setDesiredAngle(value);
		raisePropertyChanged(prop_DesiredAngle);
	}
}

// FUNCTION: WEBSERVICE 0x100e76f0
void VelocityMotor::setCurrentAngle(float value)
{
	if (value != static_cast<MotorJoint*>(joint)->getCurrentAngle()) {
		static_cast<MotorJoint*>(joint)->setCurrentAngle(value);
		raisePropertyChanged(prop_CurrentAngle);
	}
}
} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFeature>();
template void RBX::Name::callDoDeclare<RBX::sFeature>();

template class RBX::FactoryProduct<RBX::Hole, RBX::Feature, RBX::sHole>;
template class RBX::Reflection::
	Described<RBX::Hole, RBX::sHole, RBX::FactoryProduct<RBX::Hole, RBX::Feature, RBX::sHole> >;
template class RBX::DescribedCreatable<RBX::Hole, RBX::Feature, RBX::sHole>;

template class RBX::FactoryProduct<RBX::MotorFeature, RBX::Feature, RBX::sMotorFeature>;
template class RBX::Reflection::Described<
	RBX::MotorFeature,
	RBX::sMotorFeature,
	RBX::FactoryProduct<RBX::MotorFeature, RBX::Feature, RBX::sMotorFeature> >;
template class RBX::DescribedCreatable<RBX::MotorFeature, RBX::Feature, RBX::sMotorFeature>;

template class RBX::NonFactoryProduct<RBX::Instance, RBX::sFeature>;
template class RBX::Reflection::
	Described<RBX::Feature, RBX::sFeature, RBX::NonFactoryProduct<RBX::Instance, RBX::sFeature> >;
template class RBX::DescribedNonCreatable<RBX::Feature, RBX::Instance, RBX::sFeature>;
