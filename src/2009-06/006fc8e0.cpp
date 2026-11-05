// from server: 100% by auto
// roc 2009-06 006fc8e0  unit: RBX::BrickBuilder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc8e0
//
// 006fc8e0  8b442404             mov eax, dword ptr [esp + 4]
// 006fc8e4  8b4808               mov ecx, dword ptr [eax + 8]
// 006fc8e7  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fc8eb  750e                 jne 0x6fc8fb
// 006fc8ed  8d4900               lea ecx, [ecx]
// 006fc8f0  8bc1                 mov eax, ecx
// 006fc8f2  8b4808               mov ecx, dword ptr [eax + 8]
// 006fc8f5  80793500             cmp byte ptr [ecx + 0x35], 0
// 006fc8f9  74f5                 je 0x6fc8f0
// 006fc8fb  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
