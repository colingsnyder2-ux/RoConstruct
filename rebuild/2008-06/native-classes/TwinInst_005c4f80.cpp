// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c4f80: explicit instantiation of the class the body at 005c4f80 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <string>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8datamodel/Visit.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Visit,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl(void),0>;
