// from server: 100% by auto
// roc 2008-06 005876d0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005876d0
//
// 005876d0  6a4c                 push 0x4c
// 005876d2  e849921100           call 0x6a0920
// 005876d7  83c404               add esp, 4
// 005876da  85c0                 test eax, eax
// 005876dc  7406                 je 0x5876e4
// 005876de  c70000000000         mov dword ptr [eax], 0
// 005876e4  8d4804               lea ecx, [eax + 4]
// 005876e7  85c9                 test ecx, ecx
// 005876e9  7406                 je 0x5876f1
// 005876eb  c70100000000         mov dword ptr [ecx], 0
// 005876f1  8d4808               lea ecx, [eax + 8]
// 005876f4  85c9                 test ecx, ecx
// 005876f6  7406                 je 0x5876fe
// 005876f8  c70100000000         mov dword ptr [ecx], 0
// 005876fe  c6404801             mov byte ptr [eax + 0x48], 1
// 00587702  c6404900             mov byte ptr [eax + 0x49], 0
// 00587706  c3                   ret 
// standard library map_str<pod32> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
