// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native boost::polymorphic_cast<T*, Reflection::DescribedBase> instances (inactive): vendor boost 1.34.1 boost/cast.hpp
// body (dynamic_cast, throw std::bad_cast on null), instantiated for the reflection setters' downcasts.
//   Network::Player 00492a90, Instance 005599d0, Camera 005a3cb0, Hole 0060b970, ModelInstance 004914f0, PartInstance 00585310
#include <boost/cast.hpp>
#include "Network/Player.h"
#include "v8tree/Instance.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Feature.h"

template RBX::Network::Player* boost::polymorphic_cast<RBX::Network::Player*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
template RBX::Instance* boost::polymorphic_cast<RBX::Instance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
template RBX::Camera* boost::polymorphic_cast<RBX::Camera*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
template RBX::Hole* boost::polymorphic_cast<RBX::Hole*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
template RBX::ModelInstance* boost::polymorphic_cast<RBX::ModelInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
template RBX::PartInstance* boost::polymorphic_cast<RBX::PartInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
