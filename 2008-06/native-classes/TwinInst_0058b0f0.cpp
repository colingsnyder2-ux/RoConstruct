// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0058b0f0: explicit instantiation of the class the body at 0058b0f0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/ChangeHistoryService.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::ChangeHistoryService,struct RBX::Reflection::Tuple __cdecl(void),0>;
