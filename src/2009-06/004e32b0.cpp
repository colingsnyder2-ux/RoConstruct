// from server: 100% by auto
// roc 2009-06 004e32b0  unit: RBX::Network::Replicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e32b0
//
// 004e32b0  8b442404             mov eax, dword ptr [esp + 4]
// 004e32b4  8b08                 mov ecx, dword ptr [eax]
// 004e32b6  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004e32ba  750e                 jne 0x4e32ca
// 004e32bc  8d642400             lea esp, [esp]
// 004e32c0  8bc1                 mov eax, ecx
// 004e32c2  8b08                 mov ecx, dword ptr [eax]
// 004e32c4  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 004e32c8  74f6                 je 0x4e32c0
// 004e32ca  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
