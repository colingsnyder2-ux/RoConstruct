// from server: 100% by auto
// roc 2008-06 005b6ac0  unit: RBX::DropperTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6ac0
//
// 005b6ac0  8b442404             mov eax, dword ptr [esp + 4]
// 005b6ac4  8b08                 mov ecx, dword ptr [eax]
// 005b6ac6  80793500             cmp byte ptr [ecx + 0x35], 0
// 005b6aca  750e                 jne 0x5b6ada
// 005b6acc  8d642400             lea esp, [esp]
// 005b6ad0  8bc1                 mov eax, ecx
// 005b6ad2  8b08                 mov ecx, dword ptr [eax]
// 005b6ad4  80793500             cmp byte ptr [ecx + 0x35], 0
// 005b6ad8  74f6                 je 0x5b6ad0
// 005b6ada  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
