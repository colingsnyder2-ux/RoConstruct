// from server: 100% by auto
// roc 2012-06 0093cd40  unit: RBX::ChatLine  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093cd40
//
// 0093cd40  6a5c                 push 0x5c
// 0093cd42  e8d3530400           call 0x98211a
// 0093cd47  83c404               add esp, 4
// 0093cd4a  85c0                 test eax, eax
// 0093cd4c  7406                 je 0x93cd54
// 0093cd4e  c70000000000         mov dword ptr [eax], 0
// 0093cd54  8d4804               lea ecx, [eax + 4]
// 0093cd57  85c9                 test ecx, ecx
// 0093cd59  7406                 je 0x93cd61
// 0093cd5b  c70100000000         mov dword ptr [ecx], 0
// 0093cd61  8d4808               lea ecx, [eax + 8]
// 0093cd64  85c9                 test ecx, ecx
// 0093cd66  7406                 je 0x93cd6e
// 0093cd68  c70100000000         mov dword ptr [ecx], 0
// 0093cd6e  c6405801             mov byte ptr [eax + 0x58], 1
// 0093cd72  c6405900             mov byte ptr [eax + 0x59], 0
// 0093cd76  c3                   ret 
// standard library map_str<pod48> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod48>
struct E { int v[12]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
