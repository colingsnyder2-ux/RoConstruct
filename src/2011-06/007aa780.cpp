// from server: 100% by auto
// roc 2011-06 007aa780  unit: RBX::CornerWedgePoly  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007aa780
//
// 007aa780  8b442404             mov eax, dword ptr [esp + 4]
// 007aa784  8b4808               mov ecx, dword ptr [eax + 8]
// 007aa787  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007aa78b  750e                 jne 0x7aa79b
// 007aa78d  8d4900               lea ecx, [ecx]
// 007aa790  8bc1                 mov eax, ecx
// 007aa792  8b4808               mov ecx, dword ptr [eax + 8]
// 007aa795  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 007aa799  74f5                 je 0x7aa790
// 007aa79b  c3                   ret 
// standard library set<pod16> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
