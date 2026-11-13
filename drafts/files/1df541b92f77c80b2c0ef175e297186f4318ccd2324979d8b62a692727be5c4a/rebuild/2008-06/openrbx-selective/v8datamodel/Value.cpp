#include "v8datamodel/Value.h"

#include "util/Name.h"
#include "v8datamodel/BrickColor.h"

#include <G3D/Color3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <string>

namespace RBX {

// PORT: match 2008 reflection name pointer storage.
char* sBrickColorValue = "BrickColorValue";

// PORT: match 2008 reflection name pointer storage.
char* sColor3Value = "Color3Value";

// PORT: match 2008 reflection name pointer storage.
char* sCFrameValue = "CFrameValue";

// PORT: match 2008 reflection name pointer storage.
char* sVector3Value = "Vector3Value";

// PORT: match 2008 reflection name pointer storage.
char* sStringValue = "StringValue";

// PORT: match 2008 reflection name pointer storage.
char* sDoubleValue = "NumberValue";

// PORT: match 2008 reflection name pointer storage.
char* sBoolValue = "BoolValue";

// PORT: match 2008 reflection name pointer storage.
char* sIntValue = "IntValue";

// PORT: match 2008 reflection name pointer storage.
char* sObjectValue = "ObjectValue";

template <>
const int Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = 0;
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<int, 1> Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */, void(int)> Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::desc_ValueChanged("Changed", "value");

template <>
const bool Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = false;
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<bool, 1> Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */, void(bool)> Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::desc_ValueChanged(
	"Changed", "value"
);

template <>
const double Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = 0.0;
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<double, 1> Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */, void(double)> Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::desc_ValueChanged(
	"Changed", "value"
);

template <>
const std::string Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = std::string();
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<std::string, 1> Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */, void(std::string)> Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::
	desc_ValueChanged("Changed", "value");

template <>
const G3D::Vector3 Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = G3D::Vector3(0.0f, 0.0f, 0.0f);
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<G3D::Vector3, 1> Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */, void(G3D::Vector3)> Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::
	desc_ValueChanged("Changed", "value");

template <>
const G3D::CoordinateFrame Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = G3D::CoordinateFrame();
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<G3D::CoordinateFrame, 1> Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value",
	"Data",
	&Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */::value,
	&Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */, void(G3D::CoordinateFrame)> Value<
	G3D::CoordinateFrame,
	&sCFrameValue>::desc_ValueChanged /* PORT: 2008 name-pointer template argument. */("Changed", "value");

template <>
const G3D::Color3 Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = G3D::Color3();
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<G3D::Color3, 1> Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */, void(G3D::Color3)> Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::
	desc_ValueChanged("Changed", "value");

template <>
const BrickColor Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::defaultValue = BrickColor::random();
template <>
// PORT: 2008 registration requires explicit functionality flags.
Reflection::BoundProp<BrickColor, 1> Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::desc_Value(
	"Value", "Data", &Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::value, &Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::onValueChanged
, RBX::Reflection::PropertyDescriptor::STANDARD);

template <>
Reflection::SignalDesc<Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */, void(BrickColor)> Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::
	desc_ValueChanged("Changed", "value");

// PORT: 2008 registration requires explicit functionality flags.
Reflection::RefPropDescriptor<ObjectValue, Instance> ObjectValue::desc_Value(
	"Value", "Data", &ObjectValue::getValue, &ObjectValue::setValue
, RBX::Reflection::PropertyDescriptor::STANDARD);

Reflection::SignalDesc<ObjectValue, void(boost::shared_ptr<Instance>)> ObjectValue::desc_ValueChanged(
	"Changed", "value"
);

// FUNCTION: WEBSERVICE 0x100f3b60
// FUNCTION: ROBLOX 0x00632820
void registerValueClasses()
{
	Value<int, &sIntValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<double, &sDoubleValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<bool, &sBoolValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<std::string, &sStringValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<G3D::Vector3, &sVector3Value> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<G3D::CoordinateFrame, &sCFrameValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<G3D::Color3, &sColor3Value> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	Value<BrickColor, &sBrickColorValue> /* PORT: 2008 pointer-to-name template argument. */::classDescriptor();
	ObjectValue::classDescriptor();
}

// FUNCTION: WEBSERVICE 0x100f71b0
// FUNCTION: ROBLOX 0x006359a0
// PORT: ObjectValue::setValue is inline in the 2008 header (C2084).

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<&RBX::sIntValue>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sBoolValue>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sDoubleValue>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sStringValue>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sVector3Value>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sCFrameValue>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sColor3Value>();
template const RBX::Name& RBX::Name::doDeclare<&RBX::sBrickColorValue>();
template void RBX::Name::callDoDeclare<&RBX::sIntValue>();
template void RBX::Name::callDoDeclare<&RBX::sBoolValue>();
template void RBX::Name::callDoDeclare<&RBX::sDoubleValue>();
template void RBX::Name::callDoDeclare<&RBX::sStringValue>();
template void RBX::Name::callDoDeclare<&RBX::sVector3Value>();
template void RBX::Name::callDoDeclare<&RBX::sCFrameValue>();
template void RBX::Name::callDoDeclare<&RBX::sColor3Value>();
template void RBX::Name::callDoDeclare<&RBX::sBrickColorValue>();

// PORT: 2008 reflection templates take name-pointer variable addresses.
template class RBX::FactoryProduct<RBX::Value<int, &RBX::sIntValue>, RBX::Instance, &RBX::sIntValue>;
template class RBX::Reflection::Described<
	RBX::Value<int, &RBX::sIntValue>,
	&RBX::sIntValue,
	RBX::FactoryProduct<RBX::Value<int, &RBX::sIntValue>, RBX::Instance, &RBX::sIntValue> >;
template class RBX::DescribedCreatable<RBX::Value<int, &RBX::sIntValue>, RBX::Instance, &RBX::sIntValue>;

template class RBX::FactoryProduct<RBX::Value<bool, &RBX::sBoolValue>, RBX::Instance, &RBX::sBoolValue>;
template class RBX::Reflection::Described<
	RBX::Value<bool, &RBX::sBoolValue>,
	&RBX::sBoolValue,
	RBX::FactoryProduct<RBX::Value<bool, &RBX::sBoolValue>, RBX::Instance, &RBX::sBoolValue> >;
template class RBX::DescribedCreatable<RBX::Value<bool, &RBX::sBoolValue>, RBX::Instance, &RBX::sBoolValue>;

template class RBX::FactoryProduct<RBX::Value<double, &RBX::sDoubleValue>, RBX::Instance, &RBX::sDoubleValue>;
template class RBX::Reflection::Described<
	RBX::Value<double, &RBX::sDoubleValue>,
	&RBX::sDoubleValue,
	RBX::FactoryProduct<RBX::Value<double, &RBX::sDoubleValue>, RBX::Instance, &RBX::sDoubleValue> >;
template class RBX::DescribedCreatable<RBX::Value<double, &RBX::sDoubleValue>, RBX::Instance, &RBX::sDoubleValue>;

template class RBX::FactoryProduct<RBX::Value<std::string, &RBX::sStringValue>, RBX::Instance, &RBX::sStringValue>;
template class RBX::Reflection::Described<
	RBX::Value<std::string, &RBX::sStringValue>,
	&RBX::sStringValue,
	RBX::FactoryProduct<RBX::Value<std::string, &RBX::sStringValue>, RBX::Instance, &RBX::sStringValue> >;
template class RBX::DescribedCreatable<RBX::Value<std::string, &RBX::sStringValue>, RBX::Instance, &RBX::sStringValue>;

template class RBX::FactoryProduct<RBX::Value<G3D::Vector3, &RBX::sVector3Value>, RBX::Instance, &RBX::sVector3Value>;
template class RBX::Reflection::Described<
	RBX::Value<G3D::Vector3, &RBX::sVector3Value>,
	&RBX::sVector3Value,
	RBX::FactoryProduct<RBX::Value<G3D::Vector3, &RBX::sVector3Value>, RBX::Instance, &RBX::sVector3Value> >;
template class RBX::DescribedCreatable<RBX::Value<G3D::Vector3, &RBX::sVector3Value>, RBX::Instance, &RBX::sVector3Value>;

template class RBX::
	FactoryProduct<RBX::Value<G3D::CoordinateFrame, &RBX::sCFrameValue>, RBX::Instance, &RBX::sCFrameValue>;
template class RBX::Reflection::Described<
	RBX::Value<G3D::CoordinateFrame, &RBX::sCFrameValue>,
	&RBX::sCFrameValue,
	RBX::FactoryProduct<RBX::Value<G3D::CoordinateFrame, &RBX::sCFrameValue>, RBX::Instance, &RBX::sCFrameValue> >;
template class RBX::
	DescribedCreatable<RBX::Value<G3D::CoordinateFrame, &RBX::sCFrameValue>, RBX::Instance, &RBX::sCFrameValue>;

template class RBX::FactoryProduct<RBX::Value<G3D::Color3, &RBX::sColor3Value>, RBX::Instance, &RBX::sColor3Value>;
template class RBX::Reflection::Described<
	RBX::Value<G3D::Color3, &RBX::sColor3Value>,
	&RBX::sColor3Value,
	RBX::FactoryProduct<RBX::Value<G3D::Color3, &RBX::sColor3Value>, RBX::Instance, &RBX::sColor3Value> >;
template class RBX::DescribedCreatable<RBX::Value<G3D::Color3, &RBX::sColor3Value>, RBX::Instance, &RBX::sColor3Value>;

template class RBX::
	FactoryProduct<RBX::Value<RBX::BrickColor, &RBX::sBrickColorValue>, RBX::Instance, &RBX::sBrickColorValue>;
template class RBX::Reflection::Described<
	RBX::Value<RBX::BrickColor, &RBX::sBrickColorValue>,
	&RBX::sBrickColorValue,
	RBX::FactoryProduct<RBX::Value<RBX::BrickColor, &RBX::sBrickColorValue>, RBX::Instance, &RBX::sBrickColorValue> >;
template class RBX::
	DescribedCreatable<RBX::Value<RBX::BrickColor, &RBX::sBrickColorValue>, RBX::Instance, &RBX::sBrickColorValue>;
template class RBX::FactoryProduct<RBX::ObjectValue, RBX::Instance, &RBX::sObjectValue>;
template class RBX::Reflection::Described<
	RBX::ObjectValue,
	&RBX::sObjectValue,
	RBX::FactoryProduct<RBX::ObjectValue, RBX::Instance, &RBX::sObjectValue> >;
template class RBX::DescribedCreatable<RBX::ObjectValue, RBX::Instance, &RBX::sObjectValue>;
