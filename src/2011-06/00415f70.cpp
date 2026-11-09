// from server: 100% by auto
// roc 2011-06 00415f70  unit: CopyVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00415f70
//
// 00415f70  6a48                 push 0x48
// 00415f72  e8e7403f00           call 0x80a05e
// 00415f77  83c404               add esp, 4
// 00415f7a  85c0                 test eax, eax
// 00415f7c  7406                 je 0x415f84
// 00415f7e  c70000000000         mov dword ptr [eax], 0
// 00415f84  8d4804               lea ecx, [eax + 4]
// 00415f87  85c9                 test ecx, ecx
// 00415f89  7406                 je 0x415f91
// 00415f8b  c70100000000         mov dword ptr [ecx], 0
// 00415f91  8d4808               lea ecx, [eax + 8]
// 00415f94  85c9                 test ecx, ecx
// 00415f96  7406                 je 0x415f9e
// 00415f98  c70100000000         mov dword ptr [ecx], 0
// 00415f9e  c6404401             mov byte ptr [eax + 0x44], 1
// 00415fa2  c6404500             mov byte ptr [eax + 0x45], 0
// 00415fa6  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
