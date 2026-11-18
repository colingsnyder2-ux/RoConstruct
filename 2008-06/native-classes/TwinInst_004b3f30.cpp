// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 004b3f30: explicit instantiation of the class the body at 004b3f30 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <boost/shared_ptr.hpp>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "Replicator.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Network::Replicator,class boost::shared_ptr<class RBX::Reflection::DescribedBase> __cdecl(void),0>;
