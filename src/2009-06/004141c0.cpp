// from server: 100% by auto
// roc 2009-06 004141c0  unit: CopyVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004141c0
//
// 004141c0  6a48                 push 0x48
// 004141c2  e871483000           call 0x718a38
// 004141c7  83c404               add esp, 4
// 004141ca  85c0                 test eax, eax
// 004141cc  7406                 je 0x4141d4
// 004141ce  c70000000000         mov dword ptr [eax], 0
// 004141d4  8d4804               lea ecx, [eax + 4]
// 004141d7  85c9                 test ecx, ecx
// 004141d9  7406                 je 0x4141e1
// 004141db  c70100000000         mov dword ptr [ecx], 0
// 004141e1  8d4808               lea ecx, [eax + 8]
// 004141e4  85c9                 test ecx, ecx
// 004141e6  7406                 je 0x4141ee
// 004141e8  c70100000000         mov dword ptr [ecx], 0
// 004141ee  c6404401             mov byte ptr [eax + 0x44], 1
// 004141f2  c6404500             mov byte ptr [eax + 0x45], 0
// 004141f6  c3                   ret 
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
