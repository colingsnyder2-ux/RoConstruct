// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00561490: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/NativeContentProvider.h"

template std::list<RBX::ContentRequest, std::allocator<RBX::ContentRequest> >::_Nodeptr
std::list<RBX::ContentRequest, std::allocator<RBX::ContentRequest> >::_Buynode(
	std::list<RBX::ContentRequest, std::allocator<RBX::ContentRequest> >::_Nodeptr,
	std::list<RBX::ContentRequest, std::allocator<RBX::ContentRequest> >::_Nodeptr,
	const RBX::ContentRequest &);
