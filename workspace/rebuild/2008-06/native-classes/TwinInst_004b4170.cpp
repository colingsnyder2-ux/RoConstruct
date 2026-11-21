// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004b4170: explicit instantiation of the class the body at 004b4170 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <boost/shared_ptr.hpp>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "Replicator.h"
#include "v8tree/Instance.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Network::Replicator,class boost::shared_ptr<class RBX::Instance> __cdecl(void),0>;
