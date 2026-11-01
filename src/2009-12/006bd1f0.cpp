// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_ac8dd88f66dc5191.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Color3.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#undef _RELEASEASSERT
#include "reflection/object.h"
#include "reflection/signal.h"
namespace RBX { class Instance; }
template void RBX::Reflection::SignalDescImpl<2,void(boost::shared_ptr<RBX::Instance>,float)>::fire(RBX::Reflection::SignalSource*,boost::shared_ptr<RBX::Instance>,float);
template void RBX::Reflection::SignalDescImpl<1,void(boost::shared_ptr<RBX::Instance>)>::fire(RBX::Reflection::SignalSource*,const boost::shared_ptr<RBX::Instance>);
template void RBX::Reflection::SignalDescImpl<1,void(float)>::fire(RBX::Reflection::SignalSource*,const float);
template void RBX::Reflection::SignalDescImpl<0,void(void)>::fire(RBX::Reflection::SignalSource*);
template void RBX::Reflection::SignalDescImpl<1,void(bool)>::fire(RBX::Reflection::SignalSource*,bool);
template void RBX::Reflection::SignalDescImpl<1,void(int)>::fire(RBX::Reflection::SignalSource*,int);
template void RBX::Reflection::SignalDescImpl<1,void(std::string)>::fire(RBX::Reflection::SignalSource*,std::string);
template void RBX::Reflection::SignalDescImpl<1,void(G3D::Color3)>::fire(RBX::Reflection::SignalSource*,G3D::Color3);
template void RBX::Reflection::SignalDescImpl<1,void(G3D::Vector3)>::fire(RBX::Reflection::SignalSource*,G3D::Vector3);
template void RBX::Reflection::SignalDescImpl<1,void(G3D::CoordinateFrame)>::fire(RBX::Reflection::SignalSource*,G3D::CoordinateFrame);
template void RBX::Reflection::SignalDescImpl<1,void(RBX::BrickColor)>::fire(RBX::Reflection::SignalSource*,RBX::BrickColor);
template void RBX::Reflection::SignalDescImpl<1,void(const RBX::Reflection::PropertyDescriptor*)>::fire(RBX::Reflection::SignalSource*,const RBX::Reflection::PropertyDescriptor*);
template void RBX::Reflection::SignalDescImpl<2,void(std::string,int)>::fire(RBX::Reflection::SignalSource*,std::string,int);
template void RBX::Reflection::SignalDescImpl<2,void(std::string,boost::shared_ptr<RBX::Instance>)>::fire(RBX::Reflection::SignalSource*,std::string,boost::shared_ptr<RBX::Instance>);
template void RBX::Reflection::SignalDescImpl<2,void(std::string,bool)>::fire(RBX::Reflection::SignalSource*,std::string,bool);
template void RBX::Reflection::SignalDescImpl<2,void(float,float)>::fire(RBX::Reflection::SignalSource*,float,float);
