// from server: 100% by auto
// roc 2009-12 005376d0  unit: RBX::Network::Replicator  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005376d0
//
// 005376d0  8b442404             mov eax, dword ptr [esp + 4]
// 005376d4  8b08                 mov ecx, dword ptr [eax]
// 005376d6  80793500             cmp byte ptr [ecx + 0x35], 0
// 005376da  750e                 jne 0x5376ea
// 005376dc  8d642400             lea esp, [esp]
// 005376e0  8bc1                 mov eax, ecx
// 005376e2  8b08                 mov ecx, dword ptr [eax]
// 005376e4  80793500             cmp byte ptr [ecx + 0x35], 0
// 005376e8  74f6                 je 0x5376e0
// 005376ea  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
