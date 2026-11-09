// from server: 100% by auto
// roc 2010-06 00413e30  unit: CopyVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413e30
//
// 00413e30  6a48                 push 0x48
// 00413e32  e8693b3900           call 0x7a79a0
// 00413e37  83c404               add esp, 4
// 00413e3a  85c0                 test eax, eax
// 00413e3c  7406                 je 0x413e44
// 00413e3e  c70000000000         mov dword ptr [eax], 0
// 00413e44  8d4804               lea ecx, [eax + 4]
// 00413e47  85c9                 test ecx, ecx
// 00413e49  7406                 je 0x413e51
// 00413e4b  c70100000000         mov dword ptr [ecx], 0
// 00413e51  8d4808               lea ecx, [eax + 8]
// 00413e54  85c9                 test ecx, ecx
// 00413e56  7406                 je 0x413e5e
// 00413e58  c70100000000         mov dword ptr [ecx], 0
// 00413e5e  c6404401             mov byte ptr [eax + 0x44], 1
// 00413e62  c6404500             mov byte ptr [eax + 0x45], 0
// 00413e66  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
