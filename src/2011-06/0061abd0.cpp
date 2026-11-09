// from server: 100% by auto
// roc 2011-06 0061abd0  unit: RBX::VScriptContext::?$FactoryProduct  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0061abd0
//
// 0061abd0  6a4c                 push 0x4c
// 0061abd2  e887f41e00           call 0x80a05e
// 0061abd7  83c404               add esp, 4
// 0061abda  85c0                 test eax, eax
// 0061abdc  7406                 je 0x61abe4
// 0061abde  c70000000000         mov dword ptr [eax], 0
// 0061abe4  8d4804               lea ecx, [eax + 4]
// 0061abe7  85c9                 test ecx, ecx
// 0061abe9  7406                 je 0x61abf1
// 0061abeb  c70100000000         mov dword ptr [ecx], 0
// 0061abf1  8d4808               lea ecx, [eax + 8]
// 0061abf4  85c9                 test ecx, ecx
// 0061abf6  7406                 je 0x61abfe
// 0061abf8  c70100000000         mov dword ptr [ecx], 0
// 0061abfe  c6404801             mov byte ptr [eax + 0x48], 1
// 0061ac02  c6404900             mov byte ptr [eax + 0x49], 0
// 0061ac06  c3                   ret 
// standard library map_str<pod32> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
