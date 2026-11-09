// from server: 100% by auto
// roc 2011-06 0060dae0  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060dae0
//
// 0060dae0  8b442404             mov eax, dword ptr [esp + 4]
// 0060dae4  8b4808               mov ecx, dword ptr [eax + 8]
// 0060dae7  80793500             cmp byte ptr [ecx + 0x35], 0
// 0060daeb  750e                 jne 0x60dafb
// 0060daed  8d4900               lea ecx, [ecx]
// 0060daf0  8bc1                 mov eax, ecx
// 0060daf2  8b4808               mov ecx, dword ptr [eax + 8]
// 0060daf5  80793500             cmp byte ptr [ecx + 0x35], 0
// 0060daf9  74f5                 je 0x60daf0
// 0060dafb  c3                   ret 
// standard library set<pod40> (function ?_Max@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@PAU342@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
