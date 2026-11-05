// from server: 100% by auto
// roc 2012-06 0093c1c0  unit: RBX::AdornBillboarder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093c1c0
//
// 0093c1c0  8b442404             mov eax, dword ptr [esp + 4]
// 0093c1c4  8b4808               mov ecx, dword ptr [eax + 8]
// 0093c1c7  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0093c1cb  750e                 jne 0x93c1db
// 0093c1cd  8d4900               lea ecx, [ecx]
// 0093c1d0  8bc1                 mov eax, ecx
// 0093c1d2  8b4808               mov ecx, dword ptr [eax + 8]
// 0093c1d5  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0093c1d9  74f5                 je 0x93c1d0
// 0093c1db  c3                   ret 
// standard library set<pod48> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
