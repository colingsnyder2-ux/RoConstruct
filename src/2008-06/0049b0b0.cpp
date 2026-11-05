// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_unit_a0780c16a901aa2a.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("Network/Player.h","roc_unit_1cb1f788b2f04b82.cpp")
#pragma include_alias("util/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#undef _RELEASEASSERT
#pragma include_alias("reflection/reflection.h","roc_unit_8288ba8f083e2e99.cpp")
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#include "Network/Players.h"
template void RBX::Reflection::BoundFuncDesc<RBX::Network::Players,boost::shared_ptr<RBX::Instance>(int),1>::call<boost::shared_ptr<RBX::Instance>>(RBX::Network::Players*,RBX::Reflection::Value&,RBX::Reflection::Value&) const;
template void RBX::Reflection::BoundFuncDesc<RBX::Network::Players,boost::shared_ptr<RBX::Instance>(boost::shared_ptr<RBX::Instance>),1>::call<boost::shared_ptr<RBX::Instance>>(RBX::Network::Players*,RBX::Reflection::Value&,RBX::Reflection::Value&) const;
