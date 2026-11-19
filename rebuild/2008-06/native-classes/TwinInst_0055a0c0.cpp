// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0055a0c0: explicit instantiation of the class the body at 0055a0c0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Instance,void __cdecl(void),0>;
