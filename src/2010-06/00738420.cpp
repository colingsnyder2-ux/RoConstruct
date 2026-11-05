// from server: 100% by auto
// roc 2010-06 00738420  unit: seg_00730000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00738420
//
// 00738420  6a3c                 push 0x3c
// 00738422  e879f50600           call 0x7a79a0
// 00738427  83c404               add esp, 4
// 0073842a  85c0                 test eax, eax
// 0073842c  7406                 je 0x738434
// 0073842e  c70000000000         mov dword ptr [eax], 0
// 00738434  8d4804               lea ecx, [eax + 4]
// 00738437  85c9                 test ecx, ecx
// 00738439  7406                 je 0x738441
// 0073843b  c70100000000         mov dword ptr [ecx], 0
// 00738441  8d4808               lea ecx, [eax + 8]
// 00738444  85c9                 test ecx, ecx
// 00738446  7406                 je 0x73844e
// 00738448  c70100000000         mov dword ptr [ecx], 0
// 0073844e  c6403801             mov byte ptr [eax + 0x38], 1
// 00738452  c6403900             mov byte ptr [eax + 0x39], 0
// 00738456  c3                   ret 
// standard library map_int<pod40> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@XZ)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
