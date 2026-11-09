// from server: 100% by auto
// roc 2011-06 00783380  unit: RBX::Tasks::VExclusive::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00783380
//
// 00783380  6a3c                 push 0x3c
// 00783382  e8d76c0800           call 0x80a05e
// 00783387  83c404               add esp, 4
// 0078338a  85c0                 test eax, eax
// 0078338c  7406                 je 0x783394
// 0078338e  c70000000000         mov dword ptr [eax], 0
// 00783394  8d4804               lea ecx, [eax + 4]
// 00783397  85c9                 test ecx, ecx
// 00783399  7406                 je 0x7833a1
// 0078339b  c70100000000         mov dword ptr [ecx], 0
// 007833a1  8d4808               lea ecx, [eax + 8]
// 007833a4  85c9                 test ecx, ecx
// 007833a6  7406                 je 0x7833ae
// 007833a8  c70100000000         mov dword ptr [ecx], 0
// 007833ae  c6403801             mov byte ptr [eax + 0x38], 1
// 007833b2  c6403900             mov byte ptr [eax + 0x39], 0
// 007833b6  c3                   ret 
// standard library map_int<pod40> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@XZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
