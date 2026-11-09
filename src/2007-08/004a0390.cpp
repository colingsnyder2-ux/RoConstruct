// from server: 100% by auto
// roc 2007-08 004a0390  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a0390
//
// 004a0390  8b442404             mov eax, dword ptr [esp + 4]
// 004a0394  8b08                 mov ecx, dword ptr [eax]
// 004a0396  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004a039a  750e                 jne 0x4a03aa
// 004a039c  8d642400             lea esp, [esp]
// 004a03a0  8bc1                 mov eax, ecx
// 004a03a2  8b08                 mov ecx, dword ptr [eax]
// 004a03a4  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004a03a8  74f6                 je 0x4a03a0
// 004a03aa  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
