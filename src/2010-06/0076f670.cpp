// from server: 100% by auto
// roc 2010-06 0076f670  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f670
//
// 0076f670  6a4c                 push 0x4c
// 0076f672  e829830300           call 0x7a79a0
// 0076f677  83c404               add esp, 4
// 0076f67a  85c0                 test eax, eax
// 0076f67c  7406                 je 0x76f684
// 0076f67e  c70000000000         mov dword ptr [eax], 0
// 0076f684  8d4804               lea ecx, [eax + 4]
// 0076f687  85c9                 test ecx, ecx
// 0076f689  7406                 je 0x76f691
// 0076f68b  c70100000000         mov dword ptr [ecx], 0
// 0076f691  8d4808               lea ecx, [eax + 8]
// 0076f694  85c9                 test ecx, ecx
// 0076f696  7406                 je 0x76f69e
// 0076f698  c70100000000         mov dword ptr [ecx], 0
// 0076f69e  c6404801             mov byte ptr [eax + 0x48], 1
// 0076f6a2  c6404900             mov byte ptr [eax + 0x49], 0
// 0076f6a6  c3                   ret 
// standard library map_str<pod32> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
