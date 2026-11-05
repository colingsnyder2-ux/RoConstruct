// from server: 100% by auto
// roc 2009-12 007c6730  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6730
//
// 007c6730  6a4c                 push 0x4c
// 007c6732  e829d10200           call 0x7f3860
// 007c6737  83c404               add esp, 4
// 007c673a  85c0                 test eax, eax
// 007c673c  7406                 je 0x7c6744
// 007c673e  c70000000000         mov dword ptr [eax], 0
// 007c6744  8d4804               lea ecx, [eax + 4]
// 007c6747  85c9                 test ecx, ecx
// 007c6749  7406                 je 0x7c6751
// 007c674b  c70100000000         mov dword ptr [ecx], 0
// 007c6751  8d4808               lea ecx, [eax + 8]
// 007c6754  85c9                 test ecx, ecx
// 007c6756  7406                 je 0x7c675e
// 007c6758  c70100000000         mov dword ptr [ecx], 0
// 007c675e  c6404801             mov byte ptr [eax + 0x48], 1
// 007c6762  c6404900             mov byte ptr [eax + 0x49], 0
// 007c6766  c3                   ret 
// standard library map_str<pod32> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
