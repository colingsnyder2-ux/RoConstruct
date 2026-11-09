// from server: 100% by auto
// roc 2012-06 008532a0  unit: RBX::LuaStatsItem  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008532a0
//
// 008532a0  6a3c                 push 0x3c
// 008532a2  e873ee1200           call 0x98211a
// 008532a7  83c404               add esp, 4
// 008532aa  85c0                 test eax, eax
// 008532ac  7406                 je 0x8532b4
// 008532ae  c70000000000         mov dword ptr [eax], 0
// 008532b4  8d4804               lea ecx, [eax + 4]
// 008532b7  85c9                 test ecx, ecx
// 008532b9  7406                 je 0x8532c1
// 008532bb  c70100000000         mov dword ptr [ecx], 0
// 008532c1  8d4808               lea ecx, [eax + 8]
// 008532c4  85c9                 test ecx, ecx
// 008532c6  7406                 je 0x8532ce
// 008532c8  c70100000000         mov dword ptr [ecx], 0
// 008532ce  c6403801             mov byte ptr [eax + 0x38], 1
// 008532d2  c6403900             mov byte ptr [eax + 0x39], 0
// 008532d6  c3                   ret 
// standard library map_int<pod40> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@XZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
