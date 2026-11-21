// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00644420: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "set"
#include "v8world/Primitive2008.h"

template std::set<RBX::Primitive*, std::less<RBX::Primitive*>, std::allocator<RBX::Primitive*> >::set(
    std::vector<RBX::Primitive*>::iterator,
    std::vector<RBX::Primitive*>::iterator);
