// Behavioral reconstruction of value instances; not byte-verified.
#include "v8datamodel/Value.h"

namespace RBX {
template<typename T, const char* const* N> const T Value<T,N>::defaultValue = T();
template<typename T, const char* const* N>
Reflection::BoundProp<T,1> Value<T,N>::desc_Value("Value", "Data", &Value<T,N>::value, &Value<T,N>::onValueChanged, Reflection::PropertyDescriptor::STANDARD);
template<typename T, const char* const* N>
Reflection::SignalDesc<Value<T,N>, void(T)> Value<T,N>::desc_ValueChanged("Changed", "value");

template class Value<int, &sIntValue>;
template class Value<bool, &sBoolValue>;
template class Value<float, &sFloatValue>;
template class Value<std::string, &sStringValue>;
template class Value<G3D::Vector3, &sVector3Value>;
template class Value<G3D::Color3, &sColor3Value>;
template class Value<BrickColor, &sBrickColorValue>;
template class Value<G3D::CoordinateFrame, &sCFrameValue>;

void registerRecoveredValues()
{
    (void)IntValue::desc_Value;
    (void)StringValue::desc_Value;
    (void)FloatValue::desc_Value;
    (void)BoolValue::desc_Value;
    (void)ObjectValue::desc_Value;
    (void)Vector3Value::desc_Value;
    (void)Color3Value::desc_Value;
    (void)BrickColorValue::desc_Value;
    (void)CFrameValue::desc_Value;
    Creatable<Instance>::create<Vector3Value>();
    Creatable<Instance>::create<Color3Value>();
    Creatable<Instance>::create<BrickColorValue>();
    Creatable<Instance>::create<CFrameValue>();
    Creatable<Instance>::create<ObjectValue>();
    Creatable<Instance>::create<FloatValue>();
    Creatable<Instance>::create<BoolValue>();
    Creatable<Instance>::create<IntValue>();
    Creatable<Instance>::create<StringValue>();
}
}
