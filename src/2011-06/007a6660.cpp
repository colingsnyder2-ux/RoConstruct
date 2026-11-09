// from server: 100% by auto
// roc 2011-06 007a6660  unit: RBX::PrismPoly  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007a6660
//
// 007a6660  8b442404             mov eax, dword ptr [esp + 4]
// 007a6664  8b4808               mov ecx, dword ptr [eax + 8]
// 007a6667  80792500             cmp byte ptr [ecx + 0x25], 0
// 007a666b  750e                 jne 0x7a667b
// 007a666d  8d4900               lea ecx, [ecx]
// 007a6670  8bc1                 mov eax, ecx
// 007a6672  8b4808               mov ecx, dword ptr [eax + 8]
// 007a6675  80792500             cmp byte ptr [ecx + 0x25], 0
// 007a6679  74f5                 je 0x7a6670
// 007a667b  c3                   ret 
// standard library set<pod24> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
