// from server: 100% by auto
// roc 2008-06 00413be0  unit: CopyVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413be0
//
// 00413be0  6a48                 push 0x48
// 00413be2  e839cd2800           call 0x6a0920
// 00413be7  83c404               add esp, 4
// 00413bea  85c0                 test eax, eax
// 00413bec  7406                 je 0x413bf4
// 00413bee  c70000000000         mov dword ptr [eax], 0
// 00413bf4  8d4804               lea ecx, [eax + 4]
// 00413bf7  85c9                 test ecx, ecx
// 00413bf9  7406                 je 0x413c01
// 00413bfb  c70100000000         mov dword ptr [ecx], 0
// 00413c01  8d4808               lea ecx, [eax + 8]
// 00413c04  85c9                 test ecx, ecx
// 00413c06  7406                 je 0x413c0e
// 00413c08  c70100000000         mov dword ptr [ecx], 0
// 00413c0e  c6404401             mov byte ptr [eax + 0x44], 1
// 00413c12  c6404500             mov byte ptr [eax + 0x45], 0
// 00413c16  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
