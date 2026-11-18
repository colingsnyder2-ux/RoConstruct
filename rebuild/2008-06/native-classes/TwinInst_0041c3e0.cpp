// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0041c3e0: explicit instantiation of the class the body at 0041c3e0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "AppLeaves2008/DHTMLWindow2008.h"
#include "reflection/reflection.h"
#include "reflection/Metadata.h"
template class RBX::Reflection::BoundFuncDesc<class DHTMLWindow,void __cdecl(void),0>;
