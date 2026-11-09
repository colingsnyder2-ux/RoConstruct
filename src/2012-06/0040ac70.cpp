// from server: 100% by auto
// roc 2012-06 0040ac70  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ac70
//
// 0040ac70  6a48                 push 0x48
// 0040ac72  e8a3745700           call 0x98211a
// 0040ac77  83c404               add esp, 4
// 0040ac7a  85c0                 test eax, eax
// 0040ac7c  7406                 je 0x40ac84
// 0040ac7e  c70000000000         mov dword ptr [eax], 0
// 0040ac84  8d4804               lea ecx, [eax + 4]
// 0040ac87  85c9                 test ecx, ecx
// 0040ac89  7406                 je 0x40ac91
// 0040ac8b  c70100000000         mov dword ptr [ecx], 0
// 0040ac91  8d4808               lea ecx, [eax + 8]
// 0040ac94  85c9                 test ecx, ecx
// 0040ac96  7406                 je 0x40ac9e
// 0040ac98  c70100000000         mov dword ptr [ecx], 0
// 0040ac9e  c6404401             mov byte ptr [eax + 0x44], 1
// 0040aca2  c6404500             mov byte ptr [eax + 0x45], 0
// 0040aca6  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
