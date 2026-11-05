// from server: 100% by auto
// roc 2011-06 0059e470  unit: RBX::VRunService::?$EventDesc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0059e470
//
// 0059e470  8b442404             mov eax, dword ptr [esp + 4]
// 0059e474  8b08                 mov ecx, dword ptr [eax]
// 0059e476  80793500             cmp byte ptr [ecx + 0x35], 0
// 0059e47a  750e                 jne 0x59e48a
// 0059e47c  8d642400             lea esp, [esp]
// 0059e480  8bc1                 mov eax, ecx
// 0059e482  8b08                 mov ecx, dword ptr [eax]
// 0059e484  80793500             cmp byte ptr [ecx + 0x35], 0
// 0059e488  74f6                 je 0x59e480
// 0059e48a  c3                   ret 
// standard library set<pod40> (function ?_Min@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
