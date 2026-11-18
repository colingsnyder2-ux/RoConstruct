// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0058b020: explicit instantiation of the class the body at 0058b020 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/ChangeHistoryService.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::ChangeHistoryService,void __cdecl(void),0>;
