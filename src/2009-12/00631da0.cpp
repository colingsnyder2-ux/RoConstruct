// from server: 100% by auto
// roc 2009-12 00631da0  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00631da0
//
// 00631da0  8b442404             mov eax, dword ptr [esp + 4]
// 00631da4  8b08                 mov ecx, dword ptr [eax]
// 00631da6  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00631daa  750e                 jne 0x631dba
// 00631dac  8d642400             lea esp, [esp]
// 00631db0  8bc1                 mov eax, ecx
// 00631db2  8b08                 mov ecx, dword ptr [eax]
// 00631db4  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00631db8  74f6                 je 0x631db0
// 00631dba  c3                   ret 
// standard library set<pod32> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
