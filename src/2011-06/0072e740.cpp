// from server: 100% by auto
// roc 2011-06 0072e740  unit: RBX::MeshContentProvider  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072e740
//
// 0072e740  8b442404             mov eax, dword ptr [esp + 4]
// 0072e744  8b4808               mov ecx, dword ptr [eax + 8]
// 0072e747  80793100             cmp byte ptr [ecx + 0x31], 0
// 0072e74b  750e                 jne 0x72e75b
// 0072e74d  8d4900               lea ecx, [ecx]
// 0072e750  8bc1                 mov eax, ecx
// 0072e752  8b4808               mov ecx, dword ptr [eax + 8]
// 0072e755  80793100             cmp byte ptr [ecx + 0x31], 0
// 0072e759  74f5                 je 0x72e750
// 0072e75b  c3                   ret 
// standard library set<pod36> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
