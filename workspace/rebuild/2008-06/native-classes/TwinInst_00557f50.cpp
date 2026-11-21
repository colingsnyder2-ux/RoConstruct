// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00557f50: explicit instantiation of the class the body at 00557f50 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <string>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
template std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >::GetSet> RBX::Reflection::PropDescriptor<class RBX::Instance,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >::getset<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (__thiscall RBX::Instance::*)(void)const>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (__thiscall RBX::Instance::*)(void)const, int);
