// from server: 100% by auto
// roc 2011-06 007c9040  unit: RBX::ChatLine  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c9040
//
// 007c9040  6a5c                 push 0x5c
// 007c9042  e817100400           call 0x80a05e
// 007c9047  83c404               add esp, 4
// 007c904a  85c0                 test eax, eax
// 007c904c  7406                 je 0x7c9054
// 007c904e  c70000000000         mov dword ptr [eax], 0
// 007c9054  8d4804               lea ecx, [eax + 4]
// 007c9057  85c9                 test ecx, ecx
// 007c9059  7406                 je 0x7c9061
// 007c905b  c70100000000         mov dword ptr [ecx], 0
// 007c9061  8d4808               lea ecx, [eax + 8]
// 007c9064  85c9                 test ecx, ecx
// 007c9066  7406                 je 0x7c906e
// 007c9068  c70100000000         mov dword ptr [ecx], 0
// 007c906e  c6405801             mov byte ptr [eax + 0x58], 1
// 007c9072  c6405900             mov byte ptr [eax + 0x59], 0
// 007c9076  c3                   ret 
// standard library map_str<pod48> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
