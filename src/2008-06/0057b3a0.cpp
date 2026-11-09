// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_instanceintegersignale3e82c00b3c2f566.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "reflection/object.h"
#include "reflection/signal.h"
namespace RBX { class Instance; }
template void RBX::Reflection::SignalDescImpl<2,void(boost::shared_ptr<RBX::Instance>,int)>::fire(RBX::Reflection::SignalSource*,boost::shared_ptr<RBX::Instance>,int);
template void RBX::Reflection::SignalDescImpl<1,void(boost::shared_ptr<RBX::Instance>)>::fire(RBX::Reflection::SignalSource*,const boost::shared_ptr<RBX::Instance>);
template void RBX::Reflection::SignalDescImpl<1,void(int)>::fire(RBX::Reflection::SignalSource*,const int);
template void RBX::Reflection::SignalDescImpl<0,void(void)>::fire(RBX::Reflection::SignalSource*);
