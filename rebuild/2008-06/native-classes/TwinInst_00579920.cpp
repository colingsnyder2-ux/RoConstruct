// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 00579920: explicit instantiation of the class the body at 00579920 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/DataModel.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::DataModel,void __cdecl(void),0>;
