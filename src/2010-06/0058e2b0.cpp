// from server: 100% by auto
// roc 2010-06 0058e2b0  unit: seg_00580000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058e2b0
//
// 0058e2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0058e2b4  8b08                 mov ecx, dword ptr [eax]
// 0058e2b6  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0058e2ba  750e                 jne 0x58e2ca
// 0058e2bc  8d642400             lea esp, [esp]
// 0058e2c0  8bc1                 mov eax, ecx
// 0058e2c2  8b08                 mov ecx, dword ptr [eax]
// 0058e2c4  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0058e2c8  74f6                 je 0x58e2c0
// 0058e2ca  c3                   ret 
// standard library set<pod16> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
