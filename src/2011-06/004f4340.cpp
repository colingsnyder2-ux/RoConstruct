// from server: 100% by auto
// roc 2011-06 004f4340  unit: RBX::Network::Replicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f4340
//
// 004f4340  8b442404             mov eax, dword ptr [esp + 4]
// 004f4344  8b08                 mov ecx, dword ptr [eax]
// 004f4346  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004f434a  750e                 jne 0x4f435a
// 004f434c  8d642400             lea esp, [esp]
// 004f4350  8bc1                 mov eax, ecx
// 004f4352  8b08                 mov ecx, dword ptr [eax]
// 004f4354  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004f4358  74f6                 je 0x4f4350
// 004f435a  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
