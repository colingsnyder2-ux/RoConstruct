// from server: 100% by auto
// roc 2009-06 006e2370  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2370
//
// 006e2370  6a4c                 push 0x4c
// 006e2372  e8c1660300           call 0x718a38
// 006e2377  83c404               add esp, 4
// 006e237a  85c0                 test eax, eax
// 006e237c  7406                 je 0x6e2384
// 006e237e  c70000000000         mov dword ptr [eax], 0
// 006e2384  8d4804               lea ecx, [eax + 4]
// 006e2387  85c9                 test ecx, ecx
// 006e2389  7406                 je 0x6e2391
// 006e238b  c70100000000         mov dword ptr [ecx], 0
// 006e2391  8d4808               lea ecx, [eax + 8]
// 006e2394  85c9                 test ecx, ecx
// 006e2396  7406                 je 0x6e239e
// 006e2398  c70100000000         mov dword ptr [ecx], 0
// 006e239e  c6404801             mov byte ptr [eax + 0x48], 1
// 006e23a2  c6404900             mov byte ptr [eax + 0x49], 0
// 006e23a6  c3                   ret 
// standard library map_str<pod32> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
