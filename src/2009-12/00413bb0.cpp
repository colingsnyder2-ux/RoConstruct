// from server: 100% by auto
// roc 2009-12 00413bb0  unit: CopyVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413bb0
//
// 00413bb0  6a48                 push 0x48
// 00413bb2  e8a9fc3d00           call 0x7f3860
// 00413bb7  83c404               add esp, 4
// 00413bba  85c0                 test eax, eax
// 00413bbc  7406                 je 0x413bc4
// 00413bbe  c70000000000         mov dword ptr [eax], 0
// 00413bc4  8d4804               lea ecx, [eax + 4]
// 00413bc7  85c9                 test ecx, ecx
// 00413bc9  7406                 je 0x413bd1
// 00413bcb  c70100000000         mov dword ptr [ecx], 0
// 00413bd1  8d4808               lea ecx, [eax + 8]
// 00413bd4  85c9                 test ecx, ecx
// 00413bd6  7406                 je 0x413bde
// 00413bd8  c70100000000         mov dword ptr [ecx], 0
// 00413bde  c6404401             mov byte ptr [eax + 0x44], 1
// 00413be2  c6404500             mov byte ptr [eax + 0x45], 0
// 00413be6  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
