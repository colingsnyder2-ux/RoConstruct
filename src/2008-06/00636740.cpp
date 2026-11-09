// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_8f14fe51fb161553.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/signal.h","roc_unit_aa2ce3693f676441.cpp")
#undef _RELEASEASSERT
#include "G3D/Color3.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include "reflection/object.h"
#include "reflection/signal.h"
namespace RBX { class Instance; namespace Reflection {
template<class S> SignalDescImpl<0,S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* p):wrapper(p) {}
template<class S> boost::signals::connection SignalDescImpl<0,S>::connectGeneric(SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const { return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper),pos); }
template<class S> SignalDescImpl<1,S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* p):wrapper(p) {}
template<class S> boost::signals::connection SignalDescImpl<1,S>::connectGeneric(SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const { return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper),pos); }
template<class S> SignalDescImpl<2,S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* p):wrapper(p) {}
template<class S> boost::signals::connection SignalDescImpl<2,S>::connectGeneric(SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const { return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper),pos); }
template<class S> void SignalDescImpl<0,S>::GenericSlotAdapter::operator()() { std::vector<boost::any> args; wrapper->execute(args); }
template<class S> void SignalDescImpl<2,S>::GenericSlotAdapter::operator()(typename boost::function_traits<S>::arg1_type a,typename boost::function_traits<S>::arg2_type b) { std::vector<boost::any> args(2); args[0]=a; args[1]=b; wrapper->execute(args); }
}}
template class RBX::Reflection::SignalDescImpl<0,void()>;
template class RBX::Reflection::SignalDescImpl<1,void(float)>;
template class RBX::Reflection::SignalDescImpl<1,void(boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::SignalDescImpl<2,void(boost::shared_ptr<RBX::Instance>,float)>;
template class RBX::Reflection::SignalDescImpl<1,void(bool)>;
template class RBX::Reflection::SignalDescImpl<1,void(int)>;
template class RBX::Reflection::SignalDescImpl<1,void(std::string)>;
template class RBX::Reflection::SignalDescImpl<1,void(G3D::Color3)>;
template class RBX::Reflection::SignalDescImpl<1,void(G3D::Vector3)>;
template class RBX::Reflection::SignalDescImpl<1,void(G3D::CoordinateFrame)>;
template class RBX::Reflection::SignalDescImpl<1,void(RBX::BrickColor)>;
template class RBX::Reflection::SignalDescImpl<1,void(const RBX::Reflection::PropertyDescriptor*)>;
template class RBX::Reflection::SignalDescImpl<2,void(std::string,int)>;
template class RBX::Reflection::SignalDescImpl<2,void(std::string,boost::shared_ptr<RBX::Instance>)>;
template class RBX::Reflection::SignalDescImpl<2,void(std::string,bool)>;
template class RBX::Reflection::SignalDescImpl<2,void(float,float)>;
