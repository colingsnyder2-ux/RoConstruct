// from server: 100% by auto
// roc 2009-12 0047f470  unit: RBX::AdornRbxGfx  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f470
//
// 0047f470  6a3c                 push 0x3c
// 0047f472  e8e9433700           call 0x7f3860
// 0047f477  83c404               add esp, 4
// 0047f47a  85c0                 test eax, eax
// 0047f47c  7406                 je 0x47f484
// 0047f47e  c70000000000         mov dword ptr [eax], 0
// 0047f484  8d4804               lea ecx, [eax + 4]
// 0047f487  85c9                 test ecx, ecx
// 0047f489  7406                 je 0x47f491
// 0047f48b  c70100000000         mov dword ptr [ecx], 0
// 0047f491  8d4808               lea ecx, [eax + 8]
// 0047f494  85c9                 test ecx, ecx
// 0047f496  7406                 je 0x47f49e
// 0047f498  c70100000000         mov dword ptr [ecx], 0
// 0047f49e  c6403801             mov byte ptr [eax + 0x38], 1
// 0047f4a2  c6403900             mov byte ptr [eax + 0x39], 0
// 0047f4a6  c3                   ret 
// standard library map_int<pod40> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@XZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
