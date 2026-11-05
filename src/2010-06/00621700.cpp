// from server: 100% by auto
// roc 2010-06 00621700  unit: RBX::DropperTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00621700
//
// 00621700  8b442404             mov eax, dword ptr [esp + 4]
// 00621704  8b08                 mov ecx, dword ptr [eax]
// 00621706  80793500             cmp byte ptr [ecx + 0x35], 0
// 0062170a  750e                 jne 0x62171a
// 0062170c  8d642400             lea esp, [esp]
// 00621710  8bc1                 mov eax, ecx
// 00621712  8b08                 mov ecx, dword ptr [eax]
// 00621714  80793500             cmp byte ptr [ecx + 0x35], 0
// 00621718  74f6                 je 0x621710
// 0062171a  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
