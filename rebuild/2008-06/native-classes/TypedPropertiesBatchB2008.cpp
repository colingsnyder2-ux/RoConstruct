// 2008-06 native TypedPropertiesBatchB2008 (inactive): TypedPropertyDescriptor<T>::isWriteOnly / getVariant / setVariant
// for value types that no other native unit instantiates (donor-free trial, rebuild/2008-06/out/donorfree/
// report-all-native.json). Same generic bodies as G3DTypedProperties2008.cpp / ReflectionTypedProperties2008.cpp.
#include "reflection/type.h"
#include "reflection/property.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Feature.h"
#include "v8datamodel/Hopper.h"
#include "util/NormalId.h"
#include "util/MeshId.h"
#include "util/Debug.h"
#include "Network/NetworkSettings.h"
#include "CRenderSettings.h"
#include "v8datamodel/custommesh.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/BrickColor.h"
#include "script/ThreadRef.h"
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX { class ModelInstance; }
namespace RBX { namespace Reflection {
template<class T> bool TypedPropertyDescriptor<T>::isWriteOnly() const { return getset->isWriteOnly(); }
template<class T> void TypedPropertyDescriptor<T>::getVariant(const DescribedBase* instance, Value& value) const { value = getset->getValue(instance); }
template<class T> void TypedPropertyDescriptor<T>::setVariant(DescribedBase* instance, const Value& value) const { getset->setValue(instance, value.get<T>()); }
#define INSTANTIATE(T) template bool TypedPropertyDescriptor<T>::isWriteOnly() const; template void TypedPropertyDescriptor<T>::getVariant(const DescribedBase*,Value&) const; template void TypedPropertyDescriptor<T>::setVariant(DescribedBase*,const Value&) const;
INSTANTIATE(RBX::Instance*)
INSTANTIATE(RBX::PartInstance*)
INSTANTIATE(RBX::ModelInstance*)
INSTANTIATE(RBX::Hole*)
INSTANTIATE(RBX::MeshId)
INSTANTIATE(RBX::NormalId)
INSTANTIATE(RBX::PartInstance::FormFactor)
INSTANTIATE(RBX::Feature::InOut)
INSTANTIATE(RBX::Feature::LeftRight)
INSTANTIATE(RBX::Feature::TopBottom)
INSTANTIATE(RBX::HopperBin::BinType)
INSTANTIATE(RBX::Controller::ControllerType)
INSTANTIATE(RBX::Debugable::AssertAction)
INSTANTIATE(RBX::NetworkSettings::PhysicsSendMethod)
INSTANTIATE(RBX::NetworkSettings::PhysicsReceiveMethod)
INSTANTIATE(CRenderSettings::AASamples)
INSTANTIATE(CRenderSettings::GraphicsMode)
INSTANTIATE(CRenderSettings::FrameRateManagerMode)
INSTANTIATE(CRenderSettings::AntialiasingMode)
INSTANTIATE(CRenderSettings::BevelMode)
INSTANTIATE(CRenderSettings::ShadowMode)
INSTANTIATE(RBX::SpecialShape::MeshType)
INSTANTIATE(RBX::DebugSettings::ErrorReporting)
INSTANTIATE(RBX::BrickColor)
INSTANTIATE(RBX::Lua::FunctionRef)
INSTANTIATE(boost::shared_ptr<RBX::Instance>)
INSTANTIATE(boost::shared_ptr<RBX::Reflection::DescribedBase>)
typedef boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > InstancesRef;
INSTANTIATE(InstancesRef)
#undef INSTANTIATE
}}
