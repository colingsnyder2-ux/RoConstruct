// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 004b40a0: explicit instantiation of the class the body at 004b40a0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "Replicator.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Network::Replicator,void __cdecl(void),0>;
