// from server: 100% by auto
// roc 2012-06 0093c1e0  unit: RBX::AdornBillboarder  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093c1e0
//
// 0093c1e0  8b442404             mov eax, dword ptr [esp + 4]
// 0093c1e4  8b08                 mov ecx, dword ptr [eax]
// 0093c1e6  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0093c1ea  750e                 jne 0x93c1fa
// 0093c1ec  8d642400             lea esp, [esp]
// 0093c1f0  8bc1                 mov eax, ecx
// 0093c1f2  8b08                 mov ecx, dword ptr [eax]
// 0093c1f4  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0093c1f8  74f6                 je 0x93c1f0
// 0093c1fa  c3                   ret 
// standard library set<pod48> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
