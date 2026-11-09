// from server: 100% by auto
// roc 2008-06 005b6aa0  unit: RBX::DropperTool  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6aa0
//
// 005b6aa0  8b442404             mov eax, dword ptr [esp + 4]
// 005b6aa4  8b4808               mov ecx, dword ptr [eax + 8]
// 005b6aa7  80793500             cmp byte ptr [ecx + 0x35], 0
// 005b6aab  750e                 jne 0x5b6abb
// 005b6aad  8d4900               lea ecx, [ecx]
// 005b6ab0  8bc1                 mov eax, ecx
// 005b6ab2  8b4808               mov ecx, dword ptr [eax + 8]
// 005b6ab5  80793500             cmp byte ptr [ecx + 0x35], 0
// 005b6ab9  74f5                 je 0x5b6ab0
// 005b6abb  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
